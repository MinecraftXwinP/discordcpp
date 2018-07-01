#ifndef _H_GATEWAY_
#define _H_GATEWAY_
#include <string>
#include "asio_port.hpp"

namespace discordcpp {
    class gateway {
    public:
        gateway(io_context& io);
        std::string query_gateway_endpoint();
    private:
        io_context& io;
    };
};

#endif
