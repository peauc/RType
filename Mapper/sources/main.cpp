/*
** EPITECH  PROJECT , 2020
** r-type
** File  description:
** 	No description
*/

#include <iostream>
#include "Extractor.hpp"
#include "Displayer.hpp"


int main(int ac, char **av) {
	Extractor       extractor;
	Displayer       displayer;
	std::string     dest = (ac > 2 ? av[2] : "./");
	std::string     baseName = (ac > 3 ? av[3] : "sprite");
	std::string     format = (ac > 4 ? av[4] : "default");

	if (ac > 1)
	{
		dest = (dest.back() == '/' ? dest : dest + "/");
		extractor.extractSprites(std::string(av[1]));
		displayer.displaySprites(extractor);
		if (displayer.getNeedToSave())
			displayer.saveSprites(baseName, format, dest);
	}
	else
		std::cerr << "file dest baseName format" << std::endl;
	return (0);
}
