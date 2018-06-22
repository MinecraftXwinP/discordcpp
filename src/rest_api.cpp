#include "rest_api.hpp"

namespace discordcpp {
    rest_api::rest_api(beast::asio::io_context& io): io(io) {}

    nlohmann::json reset_api::get(std::string path) {
        tcp::socket* s = socket.get();
        if (s == NULL || !s.is_open()) {
            connect();
        } 
        s = socket.get();
    }

    void rest_api::connect() {
        tcp::resolver resolver{io};
        tcp::socket socket{io};
        auto const results = resolver.resolve(DISCORD_API_HOST, 443);
        boost::asio::connect(socket, results.begin(), results.end());
        socket.set()
    }
};