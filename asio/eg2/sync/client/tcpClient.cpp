//**************************tcpClient.cpp***************************

#include <iostream>
#include "tcpClient.h"
#include <vector>
#include <boost/bind.hpp>


tcpClient::tcpClient(const tcp::endpoint &point):
    io_service(),
    endpoint(point),
    socket(io_service){
        conn();
}

void tcpClient::conn() {
    try
    {
        socket.connect(endpoint);   //Socket连接到端点
        std::cout<<"client connected "<<socket.remote_endpoint().address()<<std::endl;
        ioAction();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void tcpClient::ioAction() {
    while(true){
        boost::asio::write(socket,boost::asio::buffer("hello server"));//向Socket中写入数据
        if(socket.available()){
            std::cout<<socket.available()<<std::endl;   //获取可读取的字节数
            std::vector<char> str(socket.available()+1,0);   //定义一个vector缓冲区
            socket.receive(boost::asio::buffer(str));   //使用buffer()包装缓冲区接收数据
            std::cout<<"client received: "<<&str[0]<<std::endl;  //输出接收到的字符串
            std::string string= &str[0];
            if(string == "ok"){
                return;    //收到返回值后结束
            }
        }
    }
}

tcpClient::~tcpClient() {

}