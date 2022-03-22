//**************************client***************************

#include <iostream>
#include "tcpClient.h"
#include <boost/thread.hpp>

void openClient(const tcp::endpoint &point);

int main(int argc, char* argv[]) {
    if (argc!=2){
        std::cerr<<"Usage: "<<argv[0]<<" <port>"<<std::endl;
        return 1;
    }

    unsigned short port = std:: atoi(argv[1]);
    auto const address = boost::asio::ip::address_v4::from_string("192.168.101.252");
    tcp::endpoint point(address, port);

    std::cout<<"start"<<std::endl;
    openClient(point);
    std::cout<<"end"<<std::endl;
    return 0;
}

void openClient(const tcp::endpoint &point) {
     async_TcpClient async_client(point);
}