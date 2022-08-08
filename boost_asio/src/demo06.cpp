/* active_socket_udp.cpp */
#include <boost/asio.hpp>
#include <iostream>
#include<boost/bind.hpp>
#include<memory>
#include<functional>
#include<thread>
#include<ctime>
#include<cstdlib>

using namespace std;

//echo服务器

//课程08  异步时间服务器asio_10_recv
using boost::asio::ip::tcp;

string make_daytime_string()
{
    auto now = time(NULL);
    return ctime(&now);
}

class tcp_connection :public enable_shared_from_this<tcp_connection>
{
public:
    //typedef boost::shared_ptr<tcp_connection> pointer;  //两个等同
    using pointer = shared_ptr<tcp_connection>;
    //using pointer = boost::shared_ptr<tcp_connection>;

    static shared_ptr<tcp_connection>create(boost::asio::io_service &ioserver)
    {
      return shared_ptr<tcp_connection>(new tcp_connection(ioserver));
      //return make_shared<tcp_connection>(ioserver);  //构造函数private，不能用这个
    }

    tcp::socket &socket()
    {
       return socket_;
    }

    void start()
    {
        message = make_daytime_string(); //当前时间
        //异步操作，写入东西，写入socket发布出去，写入一个buffer里面的message,
        // boost::asio::async_write(socket_ , boost::asio::buffer(message), 
        //       boost::bind(&tcp_connection::handle_writer, shared_from_this(),  //shared_from_this智能指针，拷贝了一份地址
        //                boost::asio::placeholders::error,
        //                boost::asio::placeholders::bytes_transferred));

        auto self = shared_from_this();
        boost::asio::async_write(socket_, boost::asio::buffer(message),
                 //[self] 也一样,但是效率低  不能用&self。引用的方式
                 [self = std::move(self)](auto erro, auto bytes_transferred){
                     self->handle_writer(erro , bytes_transferred);
                 });
    }

private:
   tcp::socket socket_;
   string message;
   tcp_connection(boost::asio::io_service &io_server): socket_(io_server){}
   void handle_writer(const boost::system::error_code &erro, size_t )
   { 
     
   }

};

class tcp_server
{
public:
     //绑定端口号和客户端地址
    tcp_server(boost::asio::io_service &io_server):acceptor_(io_server, tcp::endpoint(tcp::v4(), 13))
    {
      //等待链接
      start_accept();
    }
    // void get_io_server()
    // {
    //     return io_server;
    // }
    void start_accept()
    {
       //构造一个链接的指针
       tcp_connection::pointer new_connection = 
       tcp_connection::create(acceptor_.get_io_server());

       acceptor_.async_accept(new_connection->socket(),
              boost::bind(&tcp_server::handle_accept, this, 
                    new_connection, boost::asio::placeholders::error));
    }
    
    void handle_accept(tcp_connection::pointer new_connection , const boost::system::error_code &erro)
    { 
        if(!erro)  //判断是否链接成功
        {
          new_connection->start(); //写入东西
        }
        start_accept();//接受东西
    }

   tcp::acceptor acceptor_;
//    boost::asio::io_service io_server;
};


int main()
{
   try
   {
       boost::asio::io_service io_server;
       tcp_server server(io_server);
       io_server.run();
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
   }
   
  return 0;
}