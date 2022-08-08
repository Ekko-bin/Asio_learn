/* active_socket_udp.cpp */
#include <boost/asio.hpp>
#include <iostream>
#include<boost/bind.hpp>
#include<memory>
using namespace std;

//asio课程4

void printt(const boost::system::error_code &, boost::asio::deadline_timer *t, int *count)
{
    if(*count < 5)
    {
        cout << *count << endl;
        (*count)++;

        t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
        //t->async_wait(boost::bind(printt , boost::asio::placeholders::error, t , count));
        t->async_wait([t, count](const auto &erro){printt(erro, t, count);});
    }
}

void main01()
{

   boost::asio::io_service io; //io_server是链接代码和操作系统底层的桥梁
   int count = 0;

   //时间
   boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));

   //智能指针的方式
   shared_ptr<boost::asio::deadline_timer> t1 = make_shared<boost::asio::deadline_timer>(io, boost::posix_time::seconds(1));
   
  
   //程序阻塞
   t.async_wait(boost::bind(printt,  boost::asio::placeholders::error, &t , &count));
   
   //lambda
   // t.async_wait([&t, &count](const auto& erro ){printt(erro, &t, &count);});

   //智能指针的方式
  //  auto pt = t1.get();//获得原生的指针
  //  t1->async_wait([pt, &count](const auto&erro){printt(erro , pt, &count);});

   io.run();

   cout << "dsadsadsa" << endl;
}


int main()
{

  main01();
  //main02();

  return 0;
}