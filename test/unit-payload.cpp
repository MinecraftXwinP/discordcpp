#include <gtest/gtest.h>
#include "payload.hpp"
namespace {
    TEST(Payload, GetJson) {
        const nlohmann::json data{
            {"since", 91879201},
            {"game", {
                {"name","minecraft"},
                {"type",0}
            }},
            {"status", "online"},
            {"afk", false}
        };
        // an update status op
        const discordcpp::payload p(3, data);
        const nlohmann::json result = p.get_json();
        ASSERT_EQ(3, result["op"]);
        ASSERT_EQ(data, result["d"]);
    }
}