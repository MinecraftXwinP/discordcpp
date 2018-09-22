#ifndef _H_GATEWAY_CONNECTION_
#define _H_GATEWAY_CONNECTION_
#include <boost/beast/websocket.hpp>
#include "asio_port.hpp"
#include "ssl_socket_factory.hpp"
#include "payload.hpp"
#include "discord_api.hpp"

namespace discordcpp {
    class gateway_connection {
        public:
            gateway_connection(const std::string& url,io_context& io);
            void send(payload p);
        private:
            void on_handshake(boost::system::error_code ec);
            void on_ssl_handshake(boost::system::error_code ec);
            boost::beast::websocket::stream<ssl_socket> socket;
            io_context& io;
            std::string& endpoint;
    };
};
#endif