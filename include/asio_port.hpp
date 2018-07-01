#include <boost/asio.hpp>


namespace discordcpp {
    #if BOOST_VERSION / 100 % 1000 >= 66
        typedef boost::asio::io_context io_context;
    #else
        typedef boost::asio::io_service io_service;
    #endif
};