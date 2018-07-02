#ifndef _H_ASIO_PORT_
    #define _H_ASIO_PORT_

    #if BOOST_VERSION / 100 % 1000 >= 66
        #include <boost/asio/io_context.hpp>
    #else
        #include <boost/asio/io_service.hpp>
    #endif


    namespace discordcpp {
        #if BOOST_VERSION / 100 % 1000 >= 66
            typedef boost::asio::io_context io_context;
        #else
            typedef boost::asio::io_service io_service;
        #endif
    };
#endif