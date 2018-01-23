/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifdef __unix__
#include <cstdlib>
#endif

#include <iostream>
#include <Logger.hpp>
#include "ClientGame.hpp"

int     main(int ac, char **av, char **env)
{
#ifdef __unix__
	if (env == nullptr || getenv("DISPLAY") == nullptr)
		return (1);
#endif
	//TODO Pass parameters for info connection
	try {
		if (ac < 3) {
			Logger::Log(Logger::FATAL, "./client host port "
				"[seed]");
		}
		int s = 0;
		if (av[3])
			s = std::stoi(av[3]);
		ClientGame game(av[1], av[2], static_cast<unsigned short>(s), "../AssetsId.txt");
		game.run();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
