#include <gtest/gtest.h>
#include "rest_api.hpp"

namespace {
    TEST(RestAPI, GetTargetReturnURL) {
        ASSERT_EQ("https://discordapp.com/api/gateway", discordcpp::rest_api::get_target("/gateway"));
    }
}