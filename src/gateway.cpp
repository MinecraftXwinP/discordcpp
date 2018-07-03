#include "gateway.hpp"
#include "rest_api.hpp"
#include "ssl_error.hpp"

namespace discordcpp {
	gateway::gateway(io_context&  io): io(io), state(".gateway.cbor") {
        state.load();
    }

    gateway::~gateway() {
        state.save();
    }

    std::string gateway::get_gateway_endpoint() {
        std::string endpoint;
        try {
            endpoint = state.at("url").get<std::string>();
            if (endpoint.length() > 0) {
                return endpoint;
            }
        } catch (const nlohmann::json::type_error& e) {}

        endpoint = query_gateway_endpoint();
        state["url"] = endpoint;
        return endpoint;
    }

    std::string gateway::query_gateway_endpoint() const {
        rest_api rest(io);
        try {
            return rest.get("/gateway")["url"];
        } catch (ssl_error<nlohmann::json> const& e) {
            return e.get_response()["url"];
        }
    }
}
