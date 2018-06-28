#ifndef _H_PAYLOAD_
#define _H_PAYLOAD_

#include <nlohmann/json.hpp>

namespace discordcpp {
    class payload {
        public: 
            explicit payload() {};
            payload(int op,nlohmann::json data);
            operator std::string();
            virtual nlohmann::json get_json() const;
        protected:
            int op;
            nlohmann::json data;
    };
};
#endif