//**************************Server***************************
#include <iostream>

#include "tcpServer.h"
#include <boost/thread.hpp>


void openClient(const tcp::endpoint &point);
bool openServer();

int main(int argc, char* argv[]) {
   

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
    ansyc_tcpServer ansyc_server;
    return true;
}