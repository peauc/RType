/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include <iostream>
#include "Extractor.hpp"
#include "Displayer.hpp"


int main(int ac, char **av) {
	Extractor       extractor;
	SpriteManager   spriteManager;
	Displayer       displayer(spriteManager);
	std::string     dest = (ac > 2 ? av[2] : "./");
	std::string     format = (ac > 3 ? av[3] : "default");

	if (ac > 1)
	{
		dest = (dest.back() == '/' ? dest : dest + "/");
		extractor.extractSprites(std::string(av[1]));
		spriteManager.setSprites(extractor.getSprites());
		spriteManager.setImage(extractor.getImage());
		spriteManager.setSaveInfos(std::string(av[1]), format, dest);
		displayer.displaySprites();
	}
	else
		std::cerr << "file dest baseName format" << std::endl;
	return (0);
}
