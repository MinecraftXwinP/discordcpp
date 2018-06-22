#include "gateway.hpp"

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;

namespace discordcpp {
    std::string gateway::queryEndpoint(beast::asio::io_context io) {
        tcp::resolver resolver{io};
        tcp::socket socket{io};
        auto const results = resolver.resolve(DISCORD_API_HOST, 443);
        boost::asio::connect(socket, results.begin(), results.end());
        http::request<http::string_body> request{http::verb::get, DISCORD_API_BASE}
    }
}