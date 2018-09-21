#ifndef _H_SSL_ERROR_
#define _H_SSL_ERROR_
#include <exception>
#include <boost/system/system_error.hpp>

namespace discordcpp {
    template<class R>
    class ssl_error: public std::exception {
        public:
            ssl_error(boost::system::error_code& error_code, const R& response):
                response(response),
                code(error_code) {}

            const R& get_response() const { return response; }
        private:
            const R& response;
            boost::system::error_code& code;
    };
};

#endif
