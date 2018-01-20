/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include <iostream>
#include "TileEqualizer.hpp"

TileEqualizer::TileEqualizer(std::vector<Sprite> &sprites)
		: sprites(sprites) {

}

void TileEqualizer::equalize() {
	unsigned int	start = 0;
	unsigned int	end = 1;

	while (end < this->sprites.size()) {
		while (end < this->sprites.size()
			   && (this->sprites.at(end - 1).getMaxY()
				   > this->sprites.at(end).getMinY()))
			++end;
		if (end - start > 1) {
			this->equalizeWidth(start, end);
			this->equalizeHeight(start, end);
		}
		start = end;
		++end;
	}
}

void TileEqualizer::equalizeWidth(unsigned int start, unsigned int end) {
	unsigned int	biggestWidth = this->getBiggestWidth(start, end);


	for (unsigned int index = 0; start + index < end; ++index)
		this->sprites.at(start + index).setWidth(biggestWidth);
}

void TileEqualizer::equalizeHeight(unsigned int start, unsigned int end) {
	unsigned int	minY = this->sprites.at(start).getMinY();
	unsigned int	maxY = this->sprites.at(start).getMaxY();

	for (unsigned int index = 1; start + index < end; ++index) {
		if (this->sprites.at(start + index).getMinY() < minY)
			minY = this->sprites.at(start + index).getMinY();
		if (this->sprites.at(start + index).getMaxY() > maxY)
			maxY = this->sprites.at(start + index).getMaxY();
	}
	for (unsigned int index = 0; start + index < end; ++index) {
		this->sprites.at(start + index).setMinY(minY);
		this->sprites.at(start + index).setMaxY(maxY);
	}
}

unsigned int TileEqualizer::getBiggestWidth(unsigned int start,
											unsigned int end) const {
	unsigned int	biggestWidth = this->sprites.at(start).getWidth();

	for (unsigned int index = 1; start + index < end; ++index)
		if (this->sprites.at(start + index).getWidth() > biggestWidth)
			biggestWidth = this->sprites.at(start + index).getWidth();
	return (biggestWidth);

}
