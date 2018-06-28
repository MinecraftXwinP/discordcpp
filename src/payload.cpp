#include "payload.hpp"

namespace discordcpp {
    payload::payload(int op, nlohmann::json data): op(op), data(data) {}

    payload::operator std::string() {
        return get_json().dump();
    }

    nlohmann::json payload::get_json() const {
        return nlohmann::json{
            {"op",op},
            {"d", data},
        };
    }
}