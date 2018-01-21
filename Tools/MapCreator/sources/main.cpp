/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include <iostream>
#include "WindowManager.hpp"

int main(int ac, char **av, char **env) {
	std::string     existingMap = (ac > 5 ? av[5] : "");
#ifdef __unix__
	if (env == nullptr || std::getenv("DISPLAY") == nullptr)
		return (84);
#endif
	if (ac > 4) {
		WindowManager	windowManager;

		windowManager.setEnemiesDirectory(av[1]);
		windowManager.setBackgroundsDirectory(av[2]);
		windowManager.setOutputDirectory(av[3]);
		windowManager.setExecDirectory(av[4]);
		windowManager.setExistingMap(existingMap);
		windowManager.start();
	} else
		std::cerr << "[Source directory .so -> .png] "
				"[Source directory backgrounds] "
				"[Output directory] [Exec directory] "
				"[Existing Map]" << std::endl;
	return (0);
}
