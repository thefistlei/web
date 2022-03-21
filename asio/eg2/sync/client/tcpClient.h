//**************************tcpClient.h***************************
#include <boost/asio.hpp>

using tcp=boost::asio::ip::tcp;

class tcpClient {
private:
    boost::asio::io_service io_service;
    tcp::endpoint           endpoint;
    tcp::socket             socket;

public:
    tcpClient(const tcp::endpoint &point);
    ~tcpClient();

private:
    void conn();
    void ioAction();
};