//
// Created by Clément Péau on 14/01/2018.
//

#include <iostream>
#include "AsioClient.hpp"

int main(int ac, char **av)
{
	try {
		client::AsioClient client;
		client.connect("127.0.0.1");
		client.sendMessage("Hello");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
