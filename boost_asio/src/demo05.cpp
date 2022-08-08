/* active_socket_udp.cpp */
#include <boost/asio.hpp>
#include <iostream>
#include<boost/bind.hpp>
#include<memory>
#include<functional>
#include<thread>
using namespace std;

//课程07 多线程的应用
//改为lambda
class printer1
{
public:
    printer1(boost::asio::io_service &io)
             :time_(io, boost::posix_time::seconds(1)), count_(0),
              time2_(io, boost::posix_time::seconds(1)),strand_(io)
    {

       time_.async_wait(strand_.wrap([this](const auto& erro)
       {
            this->printt1();
       }));

       time2_.async_wait(strand_.wrap([this](const auto& erro)
       {
            this->printt2();
       }));

    }

    void printt1()
    {

     if(count_ < 10)
     {
        cout << "time 1 = " << count_ << endl;
        count_++;
        time_.expires_at(time_.expires_at() + boost::posix_time::seconds(1));
        time_.async_wait(strand_.wrap([this](const auto &erro)
        {
            if(erro == boost::asio::error::operation_aborted) cout <<"cancle now" << endl;
            else this->printt1();
        }));
     }

    }
     void printt2()
    {

     if(count_ < 10)
     {
        cout << "Time 2 = " << count_ << endl;
        count_++;
        time2_.expires_at(time_.expires_at() + boost::posix_time::seconds(1));
        time2_.async_wait(strand_.wrap([this](const auto &erro)
        {
            if(erro == boost::asio::error::operation_aborted) cout <<"cancle now" << endl;
            else this->printt2();
        }));
     }

    }
    ~printer1()
    {
       ;
    }
private:
    /* data */
    boost::asio::deadline_timer time_;
    boost::asio::deadline_timer time2_;
    //保证回调的相关顺序
    boost::asio::io_service::strand strand_;
    int count_;
};


int main()
{
    boost::asio::io_service io;
    printer1 p(io);
    
    thread t([&io]
    {
       io.run();
    });
    
    //这个run不起作用
    //io.reset(); //重启
    io.run();
    t.join();
    return 0;
}