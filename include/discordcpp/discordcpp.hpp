#ifndef _H_DISCORDCPP_
#define _H_DISCORDCPP_

#include <string>
#include <map>
#include <vector>

#include "event.hpp"


namespace discordcpp {
    class client {
        public:
            void connect(std::string token);
            void registerHandler(event_type type, event_handler handler);
        private:
            std::map<event_type, std::vector<event_handler> > handlers; 
    };
};
#endif