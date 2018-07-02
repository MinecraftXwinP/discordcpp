#include "ssl_socket_factory.hpp"

namespace discordcpp {
    std::unique_ptr<ssl_socket> ssl_socket_factory::build(io_context& io,const std::string& host, const std::string& service) {
        ssl::context ctx(ssl::context::sslv23);
        ctx.set_default_verify_paths();
        
        std::unique_ptr<ssl_socket> socket = std::make_unique<ssl_socket>(io, ctx);
        socket->set_verify_mode(boost::asio::ssl::verify_none);
        tcp::resolver resolver{io};
        tcp::resolver::query query(host, service);
        auto const results = resolver.resolve(query);
        ssl::stream<tcp::socket>::lowest_layer_type& lowest_layer = socket->lowest_layer();
        // Set SNI Hostname (many hosts need this to handshake successfully)
        if(! SSL_set_tlsext_host_name(socket->native_handle(), host.c_str()))
        {
            boost::system::error_code ec{static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category()};
            throw boost::system::system_error{ec};
        }

        boost::asio::connect(lowest_layer, results.begin(), results.end());
        socket->handshake(ssl_socket::client);
        return socket;
    }
};