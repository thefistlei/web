//**************************Server***************************
#include <iostream>

#include "tcpServer.h"
#include <boost/thread.hpp>


void openClient(const tcp::endpoint &point);
bool openServer();

int main(int argc, char* argv[]) {
    if (argc != 2){
        std::cerr<<"Usage: "<<argv[0]<<" <port>"<<std::endl;
        return 1;
    }

    unsigned short port = std:: atoi(argv[1]);
    auto const address = boost::asio::ip::address_v4::from_string("192.168.0.123");
    tcp::endpoint point(address,port);

    std::cout<<"start"<<std::endl;

//    boost::thread thread([=](){
//        std::cout<<"this is server thread"<<std::endl;
//        openServer();
//    });   //服务器线程，应当保证服务器监听线程先打开
//    openClient(point);

    openServer();
    std::cout<<"end"<<std::endl;
    return 0;
}

void openClient(const tcp::endpoint &point) {
//    tcpClient client(point);
}

bool openServer(){
    tcpServer server;
    //ansyc_tcpServer ansyc_server;
    return true;
}