#ifndef _SSL_SOCKET_FACTORY_
#define _SSL_SOCKET_FACTORY_
#include <memory>
#include "discordcpp/ssl.hpp"
#include <string>

namespace discordcpp {
    class ssl_socket_factory {
        public:
            static std::unique_ptr<ssl_socket> build(io_context& io,const std::string& host, const std::string& service = "https");
    };
};
#endif