#ifndef _H_SSL_
#define _H_SSL_

#include "asio_port.hpp"
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl.hpp>

namespace ssl = boost::asio::ssl;
using tcp = boost::asio::ip::tcp;

namespace discordcpp {
    typedef ssl::stream<tcp::socket> ssl_socket;
}
#endif