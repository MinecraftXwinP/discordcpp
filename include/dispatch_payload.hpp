#ifndef _H_DISPATCH_PAYLOAD_
#define _H_DISPATCH_PAYLOAD_

#include "payload.hpp"


namespace discordcpp {
    class dispatch_payload: public payload {
        public:
            dispatch_payload(nlohmann::json data,int sequence_number, std::string event_type);
            dispatch_payload(const std::string& data);
            nlohmann::json get_json() const override;
        private:
            int seq;
            std::string event_type;
    };
};


#endif