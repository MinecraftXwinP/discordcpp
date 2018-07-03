#include <gtest/gtest.h>

#include <string>
#include <fstream>

#include "gateway.hpp"
#include "file_utils.hpp"
#include <cstdio>

namespace {

    class GatewayFixture:public ::testing::Test {
        virtual void TearDown() {
            remove(".gateway.cbor");
        }
    };

    TEST_F(GatewayFixture, GetGatewayEndpointSaveUrl) {
        boost::asio::io_context io;
        {
            discordcpp::gateway g(io);
            g.get_gateway_endpoint(); 
        }
        ASSERT_TRUE(discordcpp::file_utils::file_exists(".gateway.cbor"));
    }
}