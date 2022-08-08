/* active_socket_udp.cpp */
#include <boost/asio.hpp>
#include <iostream>
using namespace std;

//asio课程3
void main01()
{
   boost::asio::io_service io; //io_server是链接代码和操作系统底层的桥梁
   //时间
   boost::asio::deadline_timer t(io, boost::posix_time::seconds(2));
   //程序阻塞
   t.wait();
   cout << "dsadsadsa" << endl;
}


void callback(const boost::system::error_code&)
{ 
   cout << "callback1" << endl;
}
void callback2(const boost::system::error_code&)
{ 
   cout << "callback2" << endl;
}
void main02()
{
   boost::asio::io_service io; //io_server是链接代码和操作系统底层的桥梁
   //时间            io是引用
   boost::asio::deadline_timer t(io, boost::posix_time::seconds(2));

   boost::asio::deadline_timer t2(io, boost::posix_time::seconds(5));
   //异步调用
   t.async_wait(callback);
   t2.async_wait(callback2);

   cout << "start run" << endl;
   io.run();
   cout << "end run" << endl;
}


//功能一样，用的不同的库文件
void main03()
{
    boost::asio::io_service io; //io_server是链接代码和操作系统底层的桥梁
    boost::asio::steady_timer st(io);
    st.expires_from_now(std::chrono::seconds(1));
    st.wait();
}

int main()
{

  //main01();
  main02();

  return 0;
}




