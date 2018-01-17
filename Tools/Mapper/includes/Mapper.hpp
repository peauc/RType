/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#ifndef MAPPER_MAPPER_HPP
#define MAPPER_MAPPER_HPP

#include <memory>
#include "SpriteManager.hpp"
#include "Displayer.hpp"
#include "Extractor.hpp"

class Mapper {

public:

	Mapper() = default;
	~Mapper() = default;
	Mapper(const Mapper&) = delete;
	Mapper	&operator=(const Mapper&) = delete;

	void	setInfos(const std::string &filePath, const std::string &dest);
	void	start();

private:

	Extractor		extractor;
	SpriteManager	spriteManager;

	std::unique_ptr<Displayer>	displayer;
};


#endif //MAPPER_MAPPER_HPP
