#include <gtest/gtest.h>

#include <string>
#include <fstream>

#include "discordcpp/gateway.hpp"
#include "discordcpp/file_utils.hpp"
#include <cstdio>

namespace {

    class GatewayFixture:public ::testing::Test {
        virtual void TearDown() {
            remove(".gateway.cbor");
        }
    };

    TEST_F(GatewayFixture, SaveStateWhenDestructed) {
        boost::asio::io_context io;
        {
            discordcpp::gateway g(io);
        }
        ASSERT_TRUE(discordcpp::file_utils::file_exists(".gateway.cbor"));
    }
}