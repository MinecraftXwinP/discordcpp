#include "discordcpp.hpp"
#include <iostream>

namespace discordcpp {
    void client::connect(std::string token) {
        std::cout << "Token is: " << token << std::endl;
        std::cout << "No implemented yet" << std::endl;
    }

    void client::registerHandler(event_type type, event_handler handler) {
        this->handlers[type].push_back(handler);
    }
};