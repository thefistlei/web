//**************************tcpServer.h***************************
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

using tcp=boost::asio::ip::tcp;

class tcpServer {
    typedef boost::shared_ptr<tcp::socket> socket_ptr;

private:
    boost::asio::io_service io_service;
    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

public:
    tcpServer();
    ~tcpServer();

private:
    void accept();
    void do_conn(socket_ptr sock);
};