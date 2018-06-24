#ifndef _H_GATEWAY_
#define _H_GATEWAY_
#include <string>
#include <boost/asio/io_context.hpp>

namespace discordcpp {
    class gateway {
    public:
        static std::string query_gateway_endpoint(boost::asio::io_context& io);
    };
};

#endif
