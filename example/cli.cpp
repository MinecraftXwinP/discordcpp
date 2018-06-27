#include <gateway.hpp>
#include <boost/asio/io_context.hpp>
#include <iostream>

int main(int argc, char** args) {
	boost::asio::io_context io;
	discordcpp::gateway gateway(io);
	io.run();
	std::cout << "gateway endpoint: " << gateway.query_gateway_endpoint() << std::endl;
	return 0;
}
