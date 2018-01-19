/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include <iostream>
#include "Mapper.hpp"

int main(int ac, char **av, char **env) {
	Mapper			mapper;
	std::string     dest = (ac > 2 ? av[2] : "./");
	std::string		execDir = (ac > 3 ? av[3] : "./");

#ifdef __unix__
	if (env == nullptr || std::getenv("DISPLAY") == nullptr)
		return (84);
#endif

	if (ac > 3) {
		dest = (dest.back() == '/' ? dest : dest + "/");
		execDir = (execDir.back() == '/' ? execDir : execDir + "/");
		mapper.setInfos(std::string(av[1]), dest, execDir);
		mapper.start();
	} else
		std::cerr << "[Source File] [Output Directory] "
				"[Exec Directory]" << std::endl;
	return (0);
}
