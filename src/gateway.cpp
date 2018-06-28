#include "gateway.hpp"
#include "rest_api.hpp"
#include "ssl_error.hpp"

namespace discordcpp {
	gateway::gateway(io_context&  io): io(io), state(".gatway.cbor") {
        state.load();
    }

    gateway::~gateway() {
        state.save();
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
