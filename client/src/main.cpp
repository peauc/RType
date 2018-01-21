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
#include "ClientGame.hpp"

int     main(int argc, char **argv, char **env)
{
#ifdef __unix__
	if (env == nullptr || getenv("DISPLAY") == nullptr)
		return (1);
#endif
	//TODO Pass parameters for info connection
	try {
		ClientGame game("10.10.253.149", "../AssetsId.txt");
//		ClientGame game("127.0.0.1", "../AssetsId.txt");
		game.run();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
