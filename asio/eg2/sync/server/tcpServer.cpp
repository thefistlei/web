//**************************tcpServer.cpp***************************
#include <stdio.h>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include "tcpServer.h"


tcpServer::tcpServer():
    endpoint(tcp::v4(),2001),
    io_service(), 
    acceptor(io_service,endpoint)
{
    accept();
}

void tcpServer::accept() {
        socket_ptr sock(new tcp::socket(io_service));

        std::cout << "server has opened! and accept is sync"<< std::endl;
        acceptor.accept(*sock);//阻塞
        std::cout << "server accepted, client: " << sock->remote_endpoint().address() << std::endl;
        sock->send(boost::asio::buffer("hello client!"));   //发送数据
        do_conn(sock);
//        boost::thread thread(boost::bind(&tcpServer::do_conn,this,sock));

}

void tcpServer::do_conn(socket_ptr sock) {
    try{
        while(true){
            char data[512];

            size_t len = sock->read_some(boost::asio::buffer(data));
            std::cout << "server connected to client! and loop to read data" << std::endl;

            if (len > 0){
                write(*sock,boost::asio::buffer("ok",2));
                std::cout << "server recall ok"<<std::endl;
            } 
        }
    }catch(const std::exception &e){
        std::cerr<<"Server Exception:"<<e.what()<<std::endl;
    }
//    accept();
}

tcpServer::~tcpServer() {

}