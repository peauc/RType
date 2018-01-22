/*
** EPITECH  PROJECT , 2020
** r-type
** File  description:
** 	No description
*/

#include <AsioServer.hpp>
#include "RessourcesLoader.hpp"

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
		return 1;
	}
//	Engine::Game *game = new Engine::Game();
//	std::shared_ptr<RessourcesLoader> ressourcesLoader = std::shared_ptr<RessourcesLoader>(new RessourcesLoader());
//
//	game->setup(1, ressourcesLoader);
//	game->getEventList().pushBack(std::make_unique<Engine::Event>(0, 5000, -10000, false, true));
//	game->getWorld()->update();
//	game->getEventList().pushBack(std::make_unique<Engine::Event>(0, 5000, -10000, false, true));
//	game->getWorld()->update();
}

