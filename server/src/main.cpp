/*
** EPITECH  PROJECT , 2020
** r-type
** File  description:
** 	No description
*/

#include <boost/exception/diagnostic_information.hpp>
#include <AsioServer.hpp>
#include <iostream>
#include <Components/HealthComponent.hpp>
#include "Logger.hpp"

int main(int, char **)
{
	try {
		AsioServer server;
		server.start();
		while (1) {
			server.tick();
		}
	} catch (boost::system::system_error &e) {
		std::cout << "Error: " << e.what() << std::endl;
		std::cout << "Info: " << boost::diagnostic_information(e)
			  << std::endl;
		return 1;
	}
//	Engine::Game *game = new Engine::Game();
//	std::shared_ptr<RessourcesLoader> rl = std::make_shared<RessourcesLoader>();
//
//	game->setup(1, nullptr);
//	game->getWorld()->update();
}

