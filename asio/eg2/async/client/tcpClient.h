//**************************async_TcpClient.h***************************
#include <boost/asio.hpp>
#include <ctime>

using tcp=boost::asio::ip::tcp;

class async_TcpClient{
private:
    boost::asio::io_service io_service;
    tcp::endpoint endpoint;
    tcp::socket socket;
    boost::asio::steady_timer async_timer;

public:
    async_TcpClient(const tcp::endpoint &point);
    ~async_TcpClient();

private:
    void connect();
    void connect_handler(const boost::system::error_code &ec);


    void heartbeat();
    void sendheart();
    void readheart();
    void reconnect();
    void timercontrol(const bool isInit);

};