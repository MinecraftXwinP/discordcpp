#include <discordcpp/ssl_session.hpp>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <openssl/ssl.h>

namespace discordcpp {
    ssl_session::ssl_session(io_context& io,ssl::context& c, const std::string& host): ssl_socket(io, c),host(host), io(io) {
        init();
    }

    void ssl_session::init() {
        tcp::resolver resolver(io);
        tcp::resolver::query query(host, "https");
        resolver.async_resolve(query, boost::bind(&ssl_session::on_resolve, this, boost::asio::placeholders::error, boost::asio::placeholders::iterator));
    }
    void ssl_session::on_resolve(const error_code& e,tcp::resolver::results_type results) {
        if (e) {
            throw e;
        }
        setup_socket();
        async_connect(lowest_layer(),results.begin(), results.end(), boost::bind(&ssl_session::on_connect, this, boost::asio::placeholders::error));
    }

    void ssl_session::setup_socket() {
        if (!SSL_set_tlsext_host_name(native_handle(), host.c_str())) {
            boost::system::error_code ec{static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category()};
            throw boost::system::system_error{ec};
        }
    }

    void ssl_session::on_connect(const error_code& e) {
        if (e) {
            throw e;
        }
        handshake(ssl_socket::client);
    }
};
