#include <gtest/gtest.h>
#include "discordcpp/dispatch_payload.hpp"

namespace {
    TEST(DispatchPayload, GetJSON) {
        discordcpp::dispatch_payload p("hello",123, "test_event");
        const nlohmann::json j = p.get_json();
        ASSERT_EQ(0, j["op"]);
        ASSERT_EQ("hello", j["d"]);
        ASSERT_EQ(123, j["s"]);
        ASSERT_EQ("test_event", j["t"]);
    }
}