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

void Sprite::setMinX(unsigned int minX) {
	this->minX = (minX < this->minX || !this->initialized ? minX : this->minX);
}

void Sprite::setMinY(unsigned int minY) {
	this->minY = (minY < this->minY || !this->initialized ? minY : this->minY);
}

void Sprite::setMaxX(unsigned int maxX) {
	this->maxX = (maxX > this->maxX || !this->initialized ? maxX : this->maxX);
}

void Sprite::setMaxY(unsigned int maxY) {
	this->maxY = (maxY > this->maxY || !this->initialized ? maxY : this->maxY);
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

unsigned int Sprite::getWidth() const {
	return ((this->maxX + 1) - this->minX);
}

unsigned int Sprite::getHeight() const {
	return ((this->maxY + 1) - this->minY);
}
