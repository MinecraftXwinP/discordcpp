#include "discordcpp/discordcpp.hpp"
#include <iostream>

namespace discordcpp {
    void client::connect(std::string token) {
        
    }

    void client::registerHandler(event_type type, event_handler handler) {
        this->handlers[type].push_back(handler);
    }
};
