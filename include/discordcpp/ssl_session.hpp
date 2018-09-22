#ifndef _H_SSL_SESSION_
#define _H_SSL_SESSION_
#include "ssl.hpp"
#include <memory>
#include <string>
#include <boost/system/error_code.hpp>
#include <boost/asio/ip/tcp.hpp>
using error_code = boost::system::error_code;
using namespace boost::asio::ip;
namespace discordcpp {
    class ssl_session:public ssl_socket {
        // friend async_ssl_socket_factory;
        public:
            ssl_session(io_context& io,ssl::context& c,const std::string& host);
        private:
            void init();
            void on_resolve(const error_code& e,tcp::resolver::results_type result);
            void on_connect(const error_code& e);
            void setup_socket();
            const std::string& host;
            io_context& io;
    };
};
#endif