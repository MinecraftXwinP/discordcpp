#include "discordcpp/gateway_connection.hpp"

namespace discordcpp {
    gateway_connection::gateway_connection(const std::string& url,io_context& io): endpoint(url),io(io) {

    }
}