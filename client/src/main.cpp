/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <iostream>
#include "ClientGame.hpp"

int main(int ac, char **av)
{
	//TODO Pass parameters for info connection
	try {
		ClientGame game("127.0.0.1", "../AssetsId.txt");
		game.run();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
