/*
** EPITECH PROJECT , 2020
** SFMLDemo
** File description :
** No description
*/

#include "Extractor.hpp"

Extractor::Sprite::Sprite() {
	this->minX = 0;
	this->minY = 0;
	this->maxX = 0;
	this->maxY = 0;
	this->initialized = false;
}

void Extractor::Sprite::setMinX(unsigned int minX) {
	this->minX = (minX < this->minX || !this->initialized ? minX : this->minX);
}

void Extractor::Sprite::setMinY(unsigned int minY) {
	this->minY = (minY < this->minY || !this->initialized ? minY : this->minY);
}

void Extractor::Sprite::setMaxX(unsigned int maxX) {
	this->maxX = (maxX > this->maxX || !this->initialized ? maxX : this->maxX);
}

void Extractor::Sprite::setMaxY(unsigned int maxY) {
	this->maxY = (maxY > this->maxY || !this->initialized ? maxY : this->maxY);
}

void Extractor::Sprite::setInitialized(bool state) {
	this->initialized = state;
}

unsigned int Extractor::Sprite::getMinX() const {
	return (this->minX);
}

unsigned int Extractor::Sprite::getMinY() const {
	return (this->minY);
}

unsigned int Extractor::Sprite::getMaxX() const {
	return (this->maxX);
}

unsigned int Extractor::Sprite::getMaxY() const {
	return (this->maxY);
}

Extractor::Sprite::Sprite(const Extractor::Sprite &obj) {
	this->minX = obj.minX;
	this->minY = obj.minY;
	this->maxX = obj.maxX;
	this->maxY = obj.maxY;
}

Extractor::Sprite &Extractor::Sprite::operator=(const Extractor::Sprite &obj) {
	if (this != &obj)
	{
		this->minX = obj.minX;
		this->minY = obj.minY;
		this->maxX = obj.maxX;
		this->maxY = obj.maxY;
	}
	return (*this);
}

unsigned int Extractor::Sprite::getWidth() const {
	return (this->maxX - this->minX);
}

unsigned int Extractor::Sprite::getHeight() const {
	return (this->maxY - this->minY);
}

void Extractor::extractSprites(const std::string &file) {
	if (!this->image.loadFromFile(file))
		return ;
	this->createPixels(this->image.getSize().x, this->image.getSize().y);
	this->browsePixels();
}

void Extractor::createPixels(unsigned int x, unsigned int y) {
	this->pixels = std::vector<std::vector<bool>>(y, std::vector<bool>(x, false));
}

void Extractor::browsePixels() {
	for (unsigned int y = 0; y < this->pixels.size(); ++y)
	{
		for (unsigned int x = 0; x < this->pixels.at(y).size(); ++x)
		{
			this->tryCreateSprite(x, y);
		}
	}
}

void Extractor::tryCreateSprite(unsigned int x, unsigned int y) {
	if (this->image.getPixel(x, y).a != 0 && !this->pixels.at(y).at(x))
	{
		Sprite  sprite;

		sprite.setMinX(x);
		sprite.setMinY(y);
		sprite.setMaxX(x);
		sprite.setMaxY(y);
		sprite.setInitialized(true);
		this->createSprite(sprite, x, y);
		if (sprite.getWidth() > 10 && sprite.getHeight() > 10)
		{
			this->sprites.push_back(sprite);
		}
	}
}

void Extractor::createSprite(Extractor::Sprite &sprite,
                             unsigned int x, unsigned int y) {
	if (y >= 0 && y < this->pixels.size()
	    && x >= 0 && x < this->pixels.at(y).size()
	    && this->image.getPixel(x, y).a != 0 && !this->pixels.at(y).at(x))
	{
		sprite.setMinX(x);
		sprite.setMinY(y);
		sprite.setMaxX(x);
		sprite.setMaxY(y);
		this->pixels.at(y).at(x) = true;
		this->createSprite(sprite, x - 1, y);
		this->createSprite(sprite, x + 1, y);
		this->createSprite(sprite, x, y - 1);
		this->createSprite(sprite, x, y + 1);
		this->createSprite(sprite, x - 1, y - 1);
		this->createSprite(sprite, x + 1, y + 1);
		this->createSprite(sprite, x - 1, y + 1);
		this->createSprite(sprite, x + 1, y - 1);
	}
}

const sf::Image &Extractor::getImage() const {
	return (this->image);
}

const std::vector<Extractor::Sprite> &Extractor::getSprites() const {
	return (this->sprites);
}


