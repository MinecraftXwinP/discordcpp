#ifndef _H_REST_API_
#define _H_REST_API_

#include <boost/asio/ip/tcp.hpp>
#include <nlohmann/json.hpp>
#include <memory>

#define DISCORD_API_BASE "https://discordapp.com/api"
#define DISCORD_API_HOST "discordapp.com"

using tcp = boost::asio::ip::tcp;

namespace discordcpp {
    class rest_api {
        public:
            rest_api(beast::asio::io_context& io);
            nlohmann::json get(std::string path);
        private:
            beast::asio::io_context& io;
            std::unique_ptr<tcp::socket> socket;
            void connect();
    };
};

#endif