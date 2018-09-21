#include "discordcpp/gateway.hpp"
#include <iostream>
#include "discordcpp/asio_port.hpp"

int main(int argc, char** args) {
	discordcpp::io_context io;
	discordcpp::gateway gateway(io);
	io.run();
	std::cout << "gateway endpoint: " << gateway.query_gateway_endpoint() << std::endl;
	return 0;
}
