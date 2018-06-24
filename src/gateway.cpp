#include "gateway.hpp"
#include "rest_api.hpp"

namespace discordcpp {
    std::string gateway::query_gateway_endpoint(boost::asio::io_context& io) {
        rest_api rest(io);
        nlohmann::json res = rest.get("/gateway");
        return res["url"];
    }
}
