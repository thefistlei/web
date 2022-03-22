//**************************async_TcpClient.h***************************
#include <boost/asio.hpp>

using tcp=boost::asio::ip::tcp;

class async_TcpClient{
private:
    boost::asio::io_service io_service;
    tcp::endpoint endpoint;
    tcp::socket socket;

public:
    async_TcpClient(const tcp::endpoint &point);
    ~async_TcpClient();

private:
    void connect();
    void connect_handler(const boost::system::error_code &ec);
};