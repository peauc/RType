/*
** EPITECH PROJECT , 2020
** AssetsIdGenerator
** File description :
** No description
*/

#include <iostream>
#include "IdGenerator.hpp"

int main(int ac, char **av) {
	IdGenerator		idGenerator;

	if (ac > 2) {
		idGenerator.setRootDirectory(std::string(av[1]));
		idGenerator.setDest(std::string(av[2]));
		if (ac > 3) {
			std::vector<std::string>	extensions(av + 3, av + (ac - 1));

			idGenerator.setExtensions(extensions);
		}
		idGenerator.generateAssetsId();
	} else
		std::cout << "[Root directory] [Output directory] "
				"[Extension1] [Extension2]..." << std::endl;
	return (0);
}
