//**************************async_tcpServer.h***************************
#include <boost/asio.hpp>

using tcp=boost::asio::ip::tcp;

class ansyc_tcpServer{
    typedef boost::shared_ptr<tcp::socket> socket_ptr;

private:
    boost::asio::io_service io_service;
    tcp::endpoint endpoint;
    tcp::acceptor acceptor;
    socket_ptr sock;
    unsigned char str[1024];

public:
    ansyc_tcpServer();
    ~ansyc_tcpServer();

private:
    void accept();
    void handle_accept(const boost::system::error_code &ec);
    void read();
    void write();

};