//**************************async_tcpServer.cpp***************************

#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include "tcpServer.h"
#include <iostream>

ansyc_tcpServer::ansyc_tcpServer() :
    io_service(),endpoint(tcp::v4(),2001), acceptor(io_service,endpoint),sock(new tcp::socket(io_service)){
    accept();
    io_service.run();
    std::cout<<"io_service.run() is end"<<std::endl;

}

ansyc_tcpServer::~ansyc_tcpServer() {

}

void ansyc_tcpServer::accept() {
    acceptor.async_accept(*sock,[this](const boost::system::error_code &ec){
        handle_accept(ec);
    });
    std::cout<<"accept()"<<std::endl;

}

void ansyc_tcpServer::handle_accept(const boost::system::error_code &ec) {
    if(ec){
        return;
    }
    read();
    std::cout<<"start another accept()"<<std::endl;
    accept();
}

void ansyc_tcpServer::read() {

    boost::asio::async_read(*sock,boost::asio::buffer(str,1024),[this](boost::system::error_code ec, std::size_t){
        if(!ec){
            write();
            std::cout<<"server received: "<<str<<std::endl;  //输出接收到的字符串
        }
        read();
    });
}

void ansyc_tcpServer::write() {
    boost::asio::async_write(*sock,boost::asio::buffer("ok",2),[this](boost::system::error_code ec, std::size_t){
        if(!ec){
            std::cout<<"server recalled: "<<str<<" ok"<<std::endl;  //输出接收到的字符串
        }
    });
}
