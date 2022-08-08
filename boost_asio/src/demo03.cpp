/* active_socket_udp.cpp */
#include <boost/asio.hpp>
#include <iostream>
// #include<boost/bind.hpp>
#include<memory>
using namespace std;

//lanbdas详解
class Lambda
{
public:
    Lambda(int b, int &c):m_b(b), m_c(c){};
    ~Lambda(){};
    void operator()(int a)
    {
       cout << a <<" and " << m_b <<"  and" << m_c << endl;
    }
private:
    /* data */
    int m_b;   //4
    int &m_c;  //8
};

void main01()
{
   //自己的lambda
   int b = 2;
   int c = 3;
   Lambda l1(2, c);
   l1(1);  //调用仿函数
   cout << sizeof(l1) << endl;

   //系统的lambda
   auto lambda2 = [b, &c](int a){cout << a <<" and " << b <<"  and" << c << endl;};
   lambda2(1);
    cout << sizeof(lambda2) << endl;
}

int main()
{
    main01();
    return 0;
}