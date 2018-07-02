#ifndef _H_REST_API_
#define _H_REST_API_

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/connect.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast.hpp>
#include <boost/asio/ssl.hpp>
#include <nlohmann/json.hpp>

#include "asio_port.hpp"
#include "ssl_socket_factory.hpp"

#define DISCORD_API_BASE "https://discordapp.com/api"
#define DISCORD_API_HOST "discordapp.com"

namespace http = boost::beast::http;
namespace discordcpp {
    class rest_api {
        public:
            rest_api(io_context& io);
            nlohmann::json get(std::string path);
            static std::string get_target(std::string path);
        private:
            io_context& io;
            // std::unique_ptr<ssl_socket> connect();
    };
};

#endif
