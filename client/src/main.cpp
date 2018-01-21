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
		client.resetChrono();
		
		Packet::DataPacket t;
		t.cmd = Packet::READY;
		client.sendMessage(t);
		while (1) {
			if (client.getChronoElapsed() > 1) {
				client.sendMessage(Packet::DataPacket
					                   (Packet::PONG));
				client.resetChrono();
			}
			client.tick();
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
