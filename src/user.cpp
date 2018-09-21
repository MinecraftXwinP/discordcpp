#include "discordcpp/user.hpp"


namespace discordcpp {
    user::user(nlohmann::json data) {
        std::istringstream iss(data.at("id").get<std::string>());
        iss >> id;
        username = data.at("username").get<std::string>();
        discriminator = data.at("discriminator").get<std::string>();
        email = data.at("email").get<std::string>();
        avatar = data.at("avatar").get<std::string>();
        mfa_enabled = data.value<bool>("mfa_enabled",false);
        verified = data.at("verified").get<bool>();
    }
}
