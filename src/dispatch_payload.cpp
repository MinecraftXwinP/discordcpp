#include "dispatch_payload.hpp"

namespace discordcpp {
    dispatch_payload::dispatch_payload(nlohmann::json data, int sequence_number, std::string event_type):
        payload(0, data),
        seq(sequence_number),
        event_type(event_type) {}
    dispatch_payload::dispatch_payload(const std::string& str): payload() {
        const nlohmann::json parsed = nlohmann::json::parse(str);
        op = parsed["op"];
        data = parsed["d"];
        seq = parsed["s"];
        event_type = parsed["t"];
    }

    nlohmann::json dispatch_payload::get_json() const {
        nlohmann::json j = payload::get_json();
        j["s"] = seq;
        j["t"] = event_type;
        return j;
    }
};