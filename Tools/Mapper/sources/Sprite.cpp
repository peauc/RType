/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include "Sprite.hpp"

Sprite::Sprite() {
	this->minX = 0;
	this->minY = 0;
	this->maxX = 0;
	this->maxY = 0;
	this->initialized = false;
}

Sprite::Sprite(const Sprite &obj) {
	this->minX = obj.minX;
	this->minY = obj.minY;
	this->maxX = obj.maxX;
	this->maxY = obj.maxY;
}

Sprite &Sprite::operator=(const Sprite &obj) {
	if (this != &obj)
	{
		this->minX = obj.minX;
		this->minY = obj.minY;
		this->maxX = obj.maxX;
		this->maxY = obj.maxY;
	}
	return (*this);
}

void Sprite::setMinX(unsigned int minX) {
	this->minX = (!this->initialized || minX < this->minX ? minX : this->minX);
}

void Sprite::setMinY(unsigned int minY) {
	this->minY = (!this->initialized || minY < this->minY ? minY : this->minY);
}

void Sprite::setMaxX(unsigned int maxX) {
	this->maxX = (!this->initialized || maxX > this->maxX ? maxX : this->maxX);
}

void Sprite::setMaxY(unsigned int maxY) {
	this->maxY = (!this->initialized || maxY > this->maxY ? maxY : this->maxY);
}

void Sprite::setInitialized(bool state) {
	this->initialized = state;
}

unsigned int Sprite::getMinX() const {
	return (this->minX);
}

unsigned int Sprite::getMinY() const {
	return (this->minY);
}

unsigned int Sprite::getMaxX() const {
	return (this->maxX);
}

unsigned int Sprite::getMaxY() const {
	return (this->maxY);
}

unsigned int Sprite::getWidth() const {
	return ((this->maxX + 1) - this->minX);
}

unsigned int Sprite::getHeight() const {
	return ((this->maxY + 1) - this->minY);
}

void Sprite::setWidth(unsigned int width) {
	int		range = (width - this->getWidth()) / 2;

	if (this->minX > 0)
		this->minX -= range;
	this->maxX += range;
	if (range == 0)
		this->maxX = this->minX + (width - 1);
}

void Sprite::setHeight(unsigned int height) {
	int		range = (height - this->getHeight()) / 2;

	if (this->minY > 0)
	this->minY -= range;
	this->maxY += range;
	if (range == 0)
		this->maxY = this->minY + (height - 1);
}
