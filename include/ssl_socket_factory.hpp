#include <boost/asio/ssl.hpp>
#include <boost/asio/connect.hpp>
#include <boost/beast/websocket/ssl.hpp>
#include <memory>

#include "asio_port.hpp"

namespace ssl = boost::asio::ssl;
using tcp = boost::asio::ip::tcp;

namespace discordcpp {
    typedef ssl::stream<tcp::socket> ssl_socket;

    class ssl_socket_factory {
        public:
            static std::unique_ptr<ssl_socket> build(io_context& io,const std::string& host, const std::string& service = "https");
    };
};