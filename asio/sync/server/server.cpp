#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace std;

int main()
{
    try
    {
        typedef ip::tcp::acceptor acceptor_type;
        typedef ip::tcp::endpoint endpoint_type;
        typedef ip::tcp::socket socket_type;

        std::cout<<"Server start."<<endl;
        io_service io;
        acceptor_type acceptor(io, endpoint_type(ip::tcp::v4(), 8080));
        std::cout<<acceptor.local_endpoint().address()<<endl;

        for (;;)
        {
            socket_type sock(io);
            acceptor.accept(sock);

            std::cout<<"Client";
            std::cout<<sock.remote_endpoint().address()<<endl;
            sock.send(buffer("Hello asio, this is server"));
        }
    }
    catch (std::exception &e)
    {
        std::cout<<e.what()<<endl;
    }

    return 0;
}