/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include "Mapper.hpp"

void Mapper::setInfos(const std::string &filePath, const std::string &dest) {
	this->extractor.extractSprites(filePath);
	this->spriteManager.setSaveInfos(filePath, dest);
}

void Mapper::start() {
	this->displayer.reset(new Displayer(this->spriteManager));
	this->spriteManager.setSprites(extractor.getSprites());
	this->spriteManager.setImage(extractor.getImage());
	this->displayer->displaySprites();
}
