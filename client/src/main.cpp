//
// Created by Clément Péau on 14/01/2018.
//

#include <iostream>
#include "AsioClient.hpp"

int main(int ac, char **av)
{
	try {
		DataPacket packet;
		client::AsioClient client;
		packet.cmd = 0;
		client.connect("127.0.0.1");
		client.sendMessage(packet);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
