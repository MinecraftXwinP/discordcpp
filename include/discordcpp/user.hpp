#ifndef _H_USER_
#define _H_USER_

#include <sstream>
#include <string>
#include <nlohmann/json.hpp>

typedef uint64_t snowflake;

namespace discordcpp {
    class user {
        public:
            user(nlohmann::json data);
            snowflake id;
            std::string username;
            std::string discriminator;
            std::string avatar;
            bool bot;
            bool mfa_enabled;
            bool verified;
            std::string email;
    };
};
#endif