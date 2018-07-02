#include "user.hpp"


namespace discordcpp {
    user::user(nlohmann::json data) {
        id = data.at("id").get<snowflake>();
        username = data.at("username").get<std::string>();
        discriminator = data.at("discriminator").get<std::string>();
        avatar = data.at("avatar").get<std::string>();
        mfa_enabled = data.at("mfa_enabled").get<bool>();
        verified = data.at("verified").get<bool>();
    }
}
