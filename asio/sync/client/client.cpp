// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace std;

int main()
{
    try
    {
        typedef ip::tcp::acceptor acceptor_type;
        typedef ip::tcp::endpoint endpoint_type;
        typedef ip::tcp::socket socket_type;
        typedef ip::address address_type;

        std::cout<<"Client start."<<endl;
        io_service io;
        socket_type sock(io);
        endpoint_type ep(address_type::from_string("49.232.107.236"), 8080);

        sock.connect(ep);

        char *hello = "Hello from client, this is 233";
        write(sock,boost::asio::buffer("Hello from client, this is 233 by asio"));    //向socket中写入字符 

        vector<char> str(100, 0);
        boost::system::error_code ec;
        for (;;)//循环接收
        {
            sock.read_some(buffer(str), ec);
            if (ec)
            {
                break;
            }
            cout<<&str[0];
        }
        // 析构自动断开连接
    }
    catch (std::exception &e)
    {
        std::cout<<e.what()<<endl;
    }
    return 0;
}