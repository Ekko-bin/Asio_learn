//
// chat_client.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include "chat_message.hpp"
#include<iostream>
using namespace std;

using boost::asio::ip::tcp;

typedef std::deque<chat_message> chat_message_queue;

class chat_client
{
public:
  chat_client(boost::asio::io_context& io_context,
                            const tcp::resolver::results_type& endpoints)
                          : io_context_(io_context),
                          socket_(io_context)
  {
      //链接服务端
      do_connect(endpoints);
  }

  void write(const chat_message& msg)
  {

    //post相当于注册一个事件，让io_context_去调度管理，run的时候才调用
    boost::asio::post(io_context_, [this, msg]()
        {
          bool write_in_progress = !write_msgs_.empty();
          write_msgs_.push_back(msg);
          if (!write_in_progress)
          {
              do_write();
          }
        });
  }

  void close()
  {
      boost::asio::post(io_context_, [this]() { socket_.close(); });
  }

private:
  void do_connect(const tcp::resolver::results_type& endpoints)
  {
    //异步
    boost::asio::async_connect(socket_, endpoints,
        [this](boost::system::error_code ec, tcp::endpoint)
        {
          //没连接上呢?
          if (!ec)
          {
                cout << "connect init"  << endl;
                do_read_header();
          }
        });
  }

  void do_read_header()
  {
    //读取头的4个字节
    boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.data(),  chat_message::header_length),
        [this](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec && read_msg_.decode_header())
          {
              do_read_body();
          }
          else
          {
            socket_.close();
          }
        });
  }

  void do_read_body()
  {
    boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
        [this](boost::system::error_code ec, std::size_t /*length*/)
        {

          if (!ec)
          {
            //处理函数，处理就是输出出来
            std::cout.write(read_msg_.body(), read_msg_.body_length());
            std::cout << "\n";
            do_read_header();
          }
          else
          {
            socket_.close();
          }
        });
  }



  void do_write()
  {
    boost::asio::async_write(socket_,  boost::asio::buffer(write_msgs_.front().data(), write_msgs_.front().length()),
        [this](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
              do_write();
            }
          }
          else
          {
            socket_.close();
          }
        });
  }

private:
  boost::asio::io_context& io_context_;
  tcp::socket socket_;
  chat_message read_msg_;
  chat_message_queue write_msgs_;

};



int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: chat_client <host> <port>\n";
      return 1;
    }

    boost::asio::io_context io_context;

    tcp::resolver resolver(io_context);

    //分析host port  93/5000   此函数用于将主机和服务名解析为*端点条目。
    auto endpoints = resolver.resolve(argv[1], argv[2]);

    chat_client c(io_context, endpoints);

    std::thread t([&io_context]()
    { io_context.run(); });

   //+1放结束符号
    char line[chat_message::max_body_length + 1];
    while (std::cin.getline(line,   chat_message::max_body_length + 1))
    {
      chat_message msg;
      msg.body_length(std::strlen(line));
    //将line的信息放到msg.body()
      std::memcpy(msg.body(),   line,   msg.body_length());
      msg.encode_header();
      c.write(msg);
    }

    c.close();
    t.join();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}