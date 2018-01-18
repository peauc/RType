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

	if (ac > 3) {
		idGenerator.setRootDirectory(std::string(av[1]));
		idGenerator.setDest(std::string(av[2]));
		idGenerator.setOrigin(av[3]);
		if (ac > 4) {
			std::vector<std::string>	extensions(av + 4, av + ac);

			idGenerator.setExtensions(extensions);
		}
		idGenerator.generateAssetsId();
	} else
		std::cout << "[Root directory] [Output directory] [Exec Directory]"
				"[Extension1] [Extension2]..." << std::endl;
	return (0);
}
