/*
** EPITECH PROJECT , 2020
** AssetsIdGenerator
** File description :
** No description
*/

#include <iostream>
#include "RessourcesLoader.hpp"

int	main()
{
	RessourcesLoader			manager;
	RessourcesLoader::Animation	animation;

	manager.loadAnimations("AssetsId.txt");
	animation = manager.getAnimations().at(0);
	for (auto &sprite : animation) {
		std::cout << "File : " << sprite.filePath << std::endl;
		std::cout << "Left : " << sprite.left << std::endl;
		std::cout << "Top : " << sprite.top << std::endl;
		std::cout << "Width : " << sprite.width << std::endl;
		std::cout << "Height : " << sprite.height << std::endl;
	}
	return (0);
}
