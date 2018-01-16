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
								 const std::string &dest) {
	this->saveSpriteIndex = 0;
	this->saveAnimationIndex = 0;
	this->source = source;
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
	if (index < this->sprites.size()) {
		this->sprites.erase(std::next(this->sprites.begin(), index));
		this->selectedSprites
				.erase(std::next(this->selectedSprites.begin(), index));
		this->removeAnimationSpriteIndex(index);
		if (index == this->sprites.size())
			return (0);
	}
	return (index);
}

void SpriteManager::removeAnimationSpriteIndex(unsigned int index) {
	auto	it = std::find(this->animationSpritesIndex.begin(),
						   this->animationSpritesIndex.end(), index);

	this->animationSpritesIndex.erase(it);
	for (auto &spriteIndex : this->animationSpritesIndex)
		if (spriteIndex > index)
			spriteIndex--;
}

void SpriteManager::setSpriteSelected(unsigned int index, bool state) {
	auto	it = std::find(this->animationSpritesIndex.begin(),
						   this->animationSpritesIndex.end(), index);

	this->selectedSprites.at(index) = state;
	if (state)
		this->animationSpritesIndex.push_back(index);
	else
		this->animationSpritesIndex.erase(it);
}

bool SpriteManager::allSelected() const {
	for (bool state : this->selectedSprites) {
		if (!state)
			return (false);
	}
	return (true);
}

bool SpriteManager::hasSomethingToSave() const {
	for (bool state : this->selectedSprites) {
		if (state)
			return (true);
	}
	return (false);
}

void SpriteManager::resetSelected() {
	for (unsigned int index = 0; index < this->selectedSprites.size(); ++index)
		this->selectedSprites.at(index) = false;
	this->animationSpritesIndex.clear();
}

void SpriteManager::saveSprites() {
	std::string     filePath;
	unsigned int    spriteIndex = 0;

	for (auto &sprite : this->sprites) {
		if (this->selectedSprites.at(spriteIndex)) {
			filePath = this->dest + "Sprite"
					   + std::to_string(this->saveSpriteIndex) + ".sprite";
			std::cout << "filePath : " << filePath << std::endl;
			std::ofstream file(filePath, std::ios::out);
			if (file) {
				file << this->jsonFormat(sprite);
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
	if (file) {
		file << this->animationFormat();
		file.close();
		this->saveAnimationIndex++;
	} else
		std::cerr << "Can't open file : " << filePath << std::endl;
}

std::string SpriteManager::animationFormat() const {
	std::string     format;

	format = "{";
	format += "\n\t Animation : ";
	format += "\n\t\t[";
	for (auto &spriteIndex : this->animationSpritesIndex) {
		format += "\n\t\t\t";
		format += this->jsonFormat(this->sprites.at(spriteIndex));
		format += ",";
	}
	if (!format.empty())
		format.erase(--(format.end()));
	format += "\n\t\t]\n}";
	return (format);
}

std::string SpriteManager::jsonFormat(const Sprite &sprite) const {
	std::string format;

	format = "{";
	format += " File : \"" + this->source + "\",";
	format += " x : " + std::to_string(sprite.getMinX()) + ",";
	format += " y : " + std::to_string(sprite.getMinY()) + ",";
	format += " width : " + std::to_string(sprite.getWidth()) + ",";
	format += " height : " + std::to_string(sprite.getHeight());
	format += " }";
	return (format);
}
