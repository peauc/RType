/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include <iostream>
#include <fstream>
#include "SpriteManager.hpp"

void SpriteManager::setSprites(const std::vector<Sprite> &sprites) {
	this->sprites = sprites;
	this->selectedSprites = std::vector<bool>(sprites.size(), false);
}

void SpriteManager::setImage(const sf::Image &image) {
	this->image = image;
}

void SpriteManager::setSaveInfos(const std::string &source,
                                 const std::string &format,
                                 const std::string &dest) {
	this->saveSpriteIndex = 0;
	this->saveAnimationIndex = 0;
	this->source = source;
	this->format = format;
	this->dest = dest;
}

bool SpriteManager::availableSprites() const {
	return (!this->sprites.empty());
}

bool SpriteManager::spriteIsSelected(unsigned int index) const {
	return (this->selectedSprites.at(index));
}

std::vector<Sprite> &SpriteManager::getSprites() {
	return (this->sprites);
}

const sf::Image &SpriteManager::getImage() const {
	return (this->image);
}

unsigned int SpriteManager::removeSprite(unsigned int index) {
	if (index < this->sprites.size())
	{
		this->sprites.erase(std::next(this->sprites.begin(), index));
		this->selectedSprites
				.erase(std::next(this->selectedSprites.begin(), index));
		if (index == this->sprites.size())
			return (0);
	}
	return (index);
}

void SpriteManager::setSpriteSelected(unsigned int index, bool state) {
	this->selectedSprites.at(index) = state;
}

bool SpriteManager::allSelected() const {
	for (bool state : this->selectedSprites)
	{
		if (!state)
		{
			return (false);
		}
	}
	return (true);
}

bool SpriteManager::hasSomethingToSave() const {
	for (bool state : this->selectedSprites)
	{
		if (state)
		{
			return (true);
		}
	}
	return (false);
}

void SpriteManager::resetSelected() {
	for (unsigned int index = 0; index < this->selectedSprites.size(); ++index)
	{
		this->selectedSprites.at(index) = false;
	}
}

void SpriteManager::saveSprites() {
	std::string     filePath;
	unsigned int    spriteIndex = 0;

	for (auto &sprite : this->sprites)
	{
		if (this->selectedSprites.at(spriteIndex)) {
			filePath = this->dest + "Sprite"
			           + std::to_string(this->saveSpriteIndex) + ".sprite";
			std::cout << "filePath : " << filePath << std::endl;
			std::ofstream file(filePath, std::ios::out);
			if (file) {
				file << (this->format == "json" ? this->jsonFormat(sprite)
				                                : this->defaultFormat(sprite));
				file.close();
				this->saveSpriteIndex++;
			} else
				std::cerr << "Can't open file : " << filePath << std::endl;
		}
		++spriteIndex;
	}
}

void SpriteManager::saveAnimation() {
	std::string     filePath;

	if (!this->hasSomethingToSave())
		return ;
	filePath = this->dest + "Animation"
	           + std::to_string(this->saveAnimationIndex) + ".anim";

	std::cout << "filePath : " << filePath << std::endl;
	std::ofstream file(filePath, std::ios::out);
	if (file)
	{
		file << this->animationFormat();
		file.close();
		this->saveAnimationIndex++;
	}
	else
		std::cerr << "Can't open file : " << filePath << std::endl;
}

std::string SpriteManager::animationFormat() const {
	std::string     format;
	unsigned int    spriteIndex = 0;

	format = "{";
	format += "\n\t Animation : ";
	format += "\n\t\t[";
	for (auto &sprite : this->sprites) {
		if (this->selectedSprites.at(spriteIndex)) {
			format += "\n\t\t\t";
			format += (this->format == "json" ? this->jsonFormat(sprite)
			                                  : this->defaultFormat(sprite));
			format += ",";
		}
		++spriteIndex;
	}
	if (!format.empty())
		format.erase(--(format.end()));
	format += "\n\t\t]\n}";
	return (format);
}

std::string SpriteManager::defaultFormat(const Sprite &sprite) const {
	std::string format;

	format = this->source + " : ";
	format += std::to_string(sprite.getMinX()) + " : ";
	format += std::to_string(sprite.getMinY()) + " : ";
	format += std::to_string(sprite.getWidth()) + " : ";
	format += std::to_string(sprite.getHeight());
	return (format);
}

std::string SpriteManager::jsonFormat(const Sprite &sprite) const {
	std::string format;

	format = "{";
	format += " File : " + this->source + ",";
	format += " x : " + std::to_string(sprite.getMinX()) + ",";
	format += " y : " + std::to_string(sprite.getMinY()) + ",";
	format += " width : " + std::to_string(sprite.getWidth()) + ",";
	format += " height : " + std::to_string(sprite.getHeight());
	format += " }";
	return (format);
}
