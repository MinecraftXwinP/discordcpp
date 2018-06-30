#include <gtest/gtest.h>

#include <string>
#include <fstream>

#include "gateway.hpp"
#include "file_utils.hpp"

namespace {

    TEST(Gateway, GetGatewayEndpointSaveUrl) {
        boost::asio::io_context io;
        {
            discordcpp::gateway g(io);
            g.get_gateway_endpoint(); 
        }
        ASSERT_TRUE(discordcpp::file_utils::file_exists(".gateway.cbor"));
    }
}