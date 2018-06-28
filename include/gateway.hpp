#ifndef _H_GATEWAY_
#define _H_GATEWAY_
#include <string>
#include "asio_port.hpp"
#include "persistent_state.hpp"

namespace discordcpp {
    class gateway {
    public:
        gateway(io_context& io);
        std::string get_gateway_endpoint();
        std::string query_gateway_endpoint() const;
        ~gateway();
    private:
        io_context& io;
        persistent_state state;
    };
};

#endif
