#include <gtest/gtest.h>
#include "discordcpp/user.hpp"

TEST(User, Deserialize) {
    const nlohmann::json input = nlohmann::json::parse(R"J(
        {
            "id": "80351110224678912",
            "username": "Nelly",
            "discriminator": "1337",
            "avatar": "8342729096ea3675442027381ff50dfe",
            "verified": true,
            "email": "nelly@discordapp.com"
        }
    )J");
    discordcpp::user u(input);

    ASSERT_EQ(80351110224678912, u.id);
    ASSERT_EQ("Nelly", u.username);
    ASSERT_EQ("1337", u.discriminator);
    ASSERT_EQ("8342729096ea3675442027381ff50dfe", u.avatar);
    ASSERT_TRUE(u.verified);
    ASSERT_EQ("nelly@discordapp.com", u.email);
}
