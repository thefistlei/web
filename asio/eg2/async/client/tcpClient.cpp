//**************************async_TcpClient.cpp***************************
#include <iostream>
#include "tcpClient.h"
#include <vector>
#include <boost/bind.hpp>

async_TcpClient::async_TcpClient(const tcp::endpoint &point):
    io_service(),endpoint(point),socket(io_service){
    connect();
    io_service.run();
    std::cout<<"io_service.run() is end!"<<std::endl;
}

void async_TcpClient::connect() {
    socket.async_connect(endpoint,[this](const boost::system::error_code &ec){
        connect_handler(ec);
    });
    std::cout<<"connect()"<<std::endl;
}

void async_TcpClient::connect_handler(const boost::system::error_code &ec) {
    std::cout<<"connected!"<<ec.message()<<std::endl;
    boost::asio::write(socket,boost::asio::buffer("hello world!",1024));

//    std::cout<<"start another accept()"<<std::endl;
//    connect();
}

async_TcpClient::~async_TcpClient() {

}