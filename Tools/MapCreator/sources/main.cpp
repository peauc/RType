/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include <iostream>
#include "WindowManager.hpp"

int main(int ac, char **av, char **env) {
	std::string     dest = (ac > 2 ? av[2] : "./");

#ifdef __unix__
	if (env == nullptr || std::getenv("DISPLAY") == nullptr)
		return (84);
#endif

	if (ac > 2) {
		WindowManager	windowManager(av[1], av[2], dest);

		windowManager.start();
	} else
		std::cerr << "[Source directory .so -> .png] "
				"[Source directory backgrounds] "
				"[Output directory]" << std::endl;
	return (0);
}
