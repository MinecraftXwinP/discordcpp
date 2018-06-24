#include <gateway.hpp>
#include <boost/asio/io_context.hpp>
#include <iostream>

int main(int argc, char** args) {
	boost::asio::io_context io;
	io.run();
	std::cout << "gateway endpoint: " << discordcpp::gateway::query_gateway_endpoint(io) << std::endl;
	return 0;
}
