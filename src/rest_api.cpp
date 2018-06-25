#include "rest_api.hpp"
#include <cstdio>
#include <iostream>



namespace discordcpp {

    
    rest_api::rest_api(boost::asio::io_context& io): io(io) {}

    nlohmann::json rest_api::get(std::string path) {
        std::unique_ptr<ssl_socket> socket = connect();
        
        std::string target = getTarget(path);
        
        http::request<http::string_body> req{http::verb::get, target, 11};
        req.set(http::field::host, DISCORD_API_HOST);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        req.set(http::field::accept, "application/json");

        http::write(*socket, req);

        boost::beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;

        http::read(*socket, buffer, res);
        if (res.base().result() != http::status::ok) {
            std::ostringstream error_message;
            error_message << "http return status: " << res.base().result_int() << ". path: " << path;
            throw std::runtime_error(error_message.str());
        }
        boost::system::error_code ec;
        socket->shutdown(ec);
        if(ec == boost::asio::error::eof)
        {
            // Rationale:
            // http://stackoverflow.com/questions/25587403/boost-asio-ssl-async-shutdown-always-finishes-with-an-error
            ec.assign(0, ec.category());
        }
        if(ec)
            throw boost::system::system_error{ec};
        return nlohmann::json::parse(boost::beast::buffers_to_string(res.body().data()));
    }

    std::unique_ptr<ssl_socket> rest_api::connect() {
        ssl::context ctx(ssl::context::sslv23);
        ctx.set_default_verify_paths();
        
        
        std::unique_ptr<ssl_socket> socket = std::make_unique<ssl_socket>(io, ctx);
        socket->set_verify_mode(boost::asio::ssl::verify_none);
        tcp::resolver resolver{io};
        tcp::resolver::query query(DISCORD_API_HOST, "https");
        auto const results = resolver.resolve(query);
        ssl::stream<tcp::socket>::lowest_layer_type& lowest_layer = socket->lowest_layer();
        // Set SNI Hostname (many hosts need this to handshake successfully)
        if(! SSL_set_tlsext_host_name(socket->native_handle(), DISCORD_API_HOST))
        {
            boost::system::error_code ec{static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category()};
            throw boost::system::system_error{ec};
        }

        boost::asio::connect(lowest_layer, results.begin(), results.end());
        socket->handshake(ssl_socket::client);
        return socket;
    }
    
    std::string rest_api::getTarget(std::string path) {
        return DISCORD_API_BASE + path;
    }

};
