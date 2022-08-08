/* active_socket_udp.cpp */
#include <boost/asio.hpp>
#include <iostream>
#include<boost/bind.hpp>
#include<memory>
#include<functional>
using namespace std;

//asio课程6
class printer
{
public:
    printer(boost::asio::io_service &io):time_(io, boost::posix_time::seconds(1)), count_(0)
    {
       time_.async_wait(std::bind(&printer::printt, this));
    }
    void printt()
    {

     if(count_ < 5)
     {
        cout << count_ << endl;
        count_++;
        time_.expires_at(time_.expires_at() + boost::posix_time::seconds(1));
        time_.async_wait(std::bind(&printer::printt, this));
     }

    }
    ~printer(){}
private:
    /* data */
    boost::asio::deadline_timer time_;
    int count_;
};



//改为lambda
class printer1
{
public:
    printer1(boost::asio::io_service &io):time_(io, boost::posix_time::seconds(5)), count_(0)
    {
       
       cout <<"构造函数" << endl;
       time_.async_wait([this](const auto &erro)
       {
          //判断一下，防止指针提前被析构了，造成野指针的存在
           if(erro == boost::asio::error::operation_aborted) cout <<"cancle now111" << endl;
           else this->printt();
       });

    }


    void printt()
    {

     if(count_ < 5)
     {
        cout << count_ << endl;
        count_++;
        time_.expires_at(time_.expires_at() + boost::posix_time::seconds(1));
        time_.async_wait([this](const auto &erro)
        {
            if(erro == boost::asio::error::operation_aborted) cout <<"cancle now printtt" << endl;
            else this->printt();
        });
     }

    }
    ~printer1()
    {
         cout << "析构函数" << endl;
    }
private:
    /* data */
    boost::asio::deadline_timer time_;
    int count_;
};



void main01()
{
  boost::asio::io_service io;

  // printer p1(io);

    //  //这样子类的生命周期结束，会出错，要确保在run之前类的生命周期还在线。
    {
    printer1 p1(io);
    cout << "dsadasda" << endl;
    }

  //跑
  io.run();
}


int main()
{

  main01();
  //main02();

  return 0;
}