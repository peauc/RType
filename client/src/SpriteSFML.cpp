/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <iostream>
#include "SpriteSFML.hpp"

SpriteSFML::SpriteSFML(const std::string &fileName,
		       unsigned int sizeTileX, unsigned int sizeTileY)
 : _sizeTileX(sizeTileX), _sizeTileY(sizeTileY)
{
	if (!this->_texture.loadFromFile(fileName)) {
		std::cerr << "[Error] Cannot open file : " + fileName
			  << std::endl;
		throw std::runtime_error("Cannot open file : " + fileName);
	} else {
		this->applyTexture();
	}
}

SpriteSFML::SpriteSFML(const SpriteSFML &other) noexcept
{
	if (this != &other) {
		this->_sprite = other._sprite;
		this->_texture = other._texture;
		this->_sizeTileX = other._sizeTileX;
		this->_sizeTileY = other._sizeTileY;
	}
}

SpriteSFML &SpriteSFML::operator=(const SpriteSFML &other) noexcept
{
	if (this != &other) {
		this->_sprite = other._sprite;
		this->_texture = other._texture;
		this->_sizeTileX = other._sizeTileX;
		this->_sizeTileY = other._sizeTileY;
	}
	return (*this);
}

void	SpriteSFML::applyTexture() noexcept
{
	this->_sprite.setTexture(this->_texture);
}

const sf::Sprite &SpriteSFML::getSprite() const noexcept
{
	return (this->_sprite);
}

void SpriteSFML::selectSprite(unsigned int posX, unsigned int posY,
			      unsigned int sizeX, unsigned int sizeY) noexcept
{
	this->_sprite.setTextureRect(sf::IntRect(posX, posY, sizeX, sizeY));
}

void SpriteSFML::selectSprite(unsigned int tileNumber,
			      unsigned int line) noexcept
{
	this->_sprite.setTextureRect(sf::IntRect(tileNumber * this->_sizeTileX,
						 line * this->_sizeTileY,
						 this->_sizeTileX,
						 this->_sizeTileY));
}
