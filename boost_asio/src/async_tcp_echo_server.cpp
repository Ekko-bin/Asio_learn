
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
using namespace std;

//课程09  //echo服务器
//客户端->服务端->客户端

//注意一下智能指针的生命周期


using boost::asio::ip::tcp;
class session: public std::enable_shared_from_this<session>
{
public:
  session(tcp::socket socket):socket_(std::move(socket))
  {
  }

  void start()
  {
    do_read();
  }

private:
  void do_read()
  {
    auto self(shared_from_this());
    //收到客户端的信息
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
        [this, self](boost::system::error_code ec, std::size_t length)
        {
          if (!ec)
          {
            do_write(length);
            // for(int i = 0 ; i < length; i++)
            // cout << "message = *" << data_[i] << endl;
          }
        });
  }


  void do_write(std::size_t length)
  {
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            do_read();
          }
        });
  }

  tcp::socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
};







class server
{
public:
  //port 端口号
  server(boost::asio::io_context& io_context, short port)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)),socket_(io_context) 
  {
    
  }
  void start()
  {
    do_accept();
  }

private:
  void do_accept()
  {
      //异步接受客户端的链接  socket_是引用
    acceptor_.async_accept(socket_ , [this](boost::system::error_code ec)
        {
          if (!ec)
          {
            std::shared_ptr<session> nesSession = std::make_shared<session>(std::move(socket_));
            nesSession->start();
          }

          do_accept();
        });
  }

  tcp::acceptor acceptor_;
  tcp::socket socket_;
};

int main(int argc, char* argv[])
{
  try
  {
    // ./ 9999
    if (argc != 2)
    {
      std::cerr << "Usage: async_tcp_echo_server <port>\n";
      return 1;
    }
    //boost_asio::io_server
    boost::asio::io_context io_context;
     
    server s(io_context,  std::atoi(argv[1]));
    s.start();
    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}