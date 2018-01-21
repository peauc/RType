/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include "Mapper.hpp"

void Mapper::setInfos(const std::string &filePath, const std::string &dest,
					  const std::string &execDir) {
	this->extractor.extractSprites(filePath);
	this->spriteManager.setSaveInfos(filePath, dest, execDir);
}

void Mapper::start() {
	this->displayer = std::make_unique<Displayer>(this->spriteManager);
	this->spriteManager.setSprites(this->extractor.getSprites());
	this->spriteManager
			.setSpritesEqualize(this->extractor.getSpritesEqualize());
	this->spriteManager.setImage(extractor.getImage());
	this->displayer->displaySprites();
}
