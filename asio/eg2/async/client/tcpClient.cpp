//**************************async_TcpClient.cpp***************************
#include <iostream>
#include "tcpClient.h"
#include <vector>
#include <boost/bind.hpp>

async_TcpClient::async_TcpClient(const tcp::endpoint &point):
    io_service(),
    endpoint(point),
    socket(io_service),
    async_timer(io_service)
{
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
    heartbeat();
}

async_TcpClient::~async_TcpClient() {

}

void async_TcpClient::heartbeat() {
    std::cout<<"heartbeat!"<<std::endl;
    sendheart();
    timercontrol(true);
}

void async_TcpClient::sendheart() {

    //发送心跳
    boost::asio::async_write(socket,boost::asio::buffer("heart beating!"),
                             [this](boost::system::error_code ec, std::size_t t){
        if(!ec){
            std::cout<<"发送心跳"<<std::endl;
            readheart();
        } else{
            //失败时则进行断线重连
            reconnect();
        }
    });
}

void async_TcpClient::readheart() {
    std::string str;

    //读取回复
    boost::asio::async_read(socket,boost::asio::buffer(&str[0],2),
                            [this](boost::system::error_code ec, std::size_t t){
        if(!ec){
            if(!ec){//这里偷了个懒，实际上是要验证通信协议中心跳包的服务器响应数据
                std::cout<<"读取回复1"<<std::endl;
//              write();
            }else{
                std::cout<<"读取回复2"<<std::endl;
                //内容不符合则进行断线重连
                reconnect();
            }
        } else{
            std::cout<<"读取回复3"<<std::endl;
            //失败时则进行断线重连
            reconnect();
        }
   });
}

void async_TcpClient::reconnect() {
    socket.close();
    socket.async_connect(endpoint,[this](const boost::system::error_code ec){
        if(!ec){
            std::cout<<"reconnected!"<<std::endl;
        }else{
            std::cout<<"reconnect failed!"<<std::endl;
        }
    });
}

void async_TcpClient::timercontrol(const bool isInit) {
    if(isInit){
        async_timer.expires_from_now(std::chrono::seconds(10));
        async_timer.async_wait([this](const boost::system::error_code& ec){
            //这里就是用来被取消的，不需要任何进行操作
        });
    }

    //每次io操作时重置定时器计时,重置时应该保证async_wait已存在
    if(async_timer.expires_from_now(std::chrono::seconds(10))>0){
        async_timer.async_wait([this](const boost::system::error_code& ec){
            if (ec != boost::asio::error::operation_aborted)
            {
                heartbeat();
            } else{
                std::cout<<"another async_timer error2 "<<ec.message()<<std::endl;
            }
        });
    } else{
        std::cout<<"1async_timer error "<<std::endl;
    }
}
