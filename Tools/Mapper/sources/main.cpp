/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include <cstdlib>
#include <iostream>
#include "Mapper.hpp"


int main(int ac, char **av, char **env) {
	Mapper			mapper;
	std::string     dest = (ac > 2 ? av[2] : "./");

#ifdef __unix__
	if (env == nullptr || std::getenv("DISPLAY") == nullptr)
		return (84);
#endif

	if (ac > 1) {
		dest = (dest.back() == '/' ? dest : dest + "/");
		mapper.setInfos(std::string(av[1]), dest);
		mapper.start();
	}
	else
		std::cerr << "[Source File] [Output Directory]" << std::endl;
	return (0);
}
