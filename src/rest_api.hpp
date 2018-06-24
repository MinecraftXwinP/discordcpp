#ifndef _H_REST_API_
#define _H_REST_API_

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/connect.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast.hpp>
#include <boost/asio/ssl.hpp>
#include <nlohmann/json.hpp>
#include <memory>

#define DISCORD_API_BASE "https://discordapp.com/api"
#define DISCORD_API_HOST "discordapp.com"

using tcp = boost::asio::ip::tcp;
namespace ssl = boost::asio::ssl;
namespace http = boost::beast::http;

namespace discordcpp {
    typedef ssl::stream<tcp::socket> ssl_socket;
    class rest_api {
        public:
            rest_api(boost::asio::io_context& io);
            nlohmann::json get(std::string path);
        private:
            boost::asio::io_context& io;
            std::unique_ptr<ssl_socket> connect();
            std::string getTarget(std::string path);
    };
};

#endif
