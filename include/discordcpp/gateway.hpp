#ifndef _H_GATEWAY_
#define _H_GATEWAY_
#include <string>
#include <boost/asio/ssl.hpp>
#include <boost/beast/websocket/ssl.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "asio_port.hpp"
#include "persistent_state.hpp"
#include "gateway_connection.hpp"

namespace ssl = boost::asio::ssl;
using tcp = boost::asio::ip::tcp;

namespace discordcpp {
    typedef ssl::stream<tcp::socket> ssl_socket;
    class gateway {
    public:
        gateway(io_context& io);
        gateway_connection& connect();
        std::string get_gateway_endpoint();
        std::string query_gateway_endpoint() const;
        ~gateway();
    private:
        io_context& io;
        persistent_state state;
        std::unique_ptr<gateway_connection> connection;
    };
};

#endif
