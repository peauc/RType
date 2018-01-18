/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include "PixelsArray.hpp"

PixelsArray::PixelsArray(std::size_t width, std::size_t height, bool init) {
	this->width = width;
	this->height = height;
	this->pixels.assign(width * height, init);
}

PixelsArray::PixelsArray(const PixelsArray &obj) {
	this->pixels = obj.pixels;
}

PixelsArray &PixelsArray::operator=(const PixelsArray &obj) {
	if (&obj != this) {
		this->pixels = obj.pixels;
	}
	return (*this);
}

std::vector<bool>::reference PixelsArray::at(unsigned int x, unsigned int y) {
	return (this->pixels.at(this->width * y + x));
}

bool PixelsArray::outOfRange(unsigned int x, unsigned int y) const {
	return (this->width * y + x > this->pixels.size());
}

std::size_t PixelsArray::getWidth() const {
	return (this->width);
}

std::size_t PixelsArray::getHeight() const {
	return (this->height);
}

