/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <iostream>
#include "Graphic/SpriteSFML.hpp"

SpriteSFML::SpriteSFML() noexcept
	: _sizeTileX(0), _sizeTileY(0)
{
}

SpriteSFML::SpriteSFML(const std::string &fileName,
		       unsigned int sizeTileX, unsigned int sizeTileY)
 : _sizeTileX(sizeTileX), _sizeTileY(sizeTileY)
{
	if (!this->_texture.loadFromFile(fileName)) {
		throw std::runtime_error("Cannot open sprite file : " +
						 fileName);
	} else {
		this->applyTexture();
	}
}

SpriteSFML::SpriteSFML(const SpriteSFML &other) noexcept
 : ASprite(other)
{
	if (this != &other) {
		this->_sprite = other._sprite;
		this->_texture = other._texture;
		this->_sizeTileX = other._sizeTileX;
		this->_sizeTileY = other._sizeTileY;
		this->_animationVector = other._animationVector;
	}
}

SpriteSFML &SpriteSFML::operator=(const SpriteSFML &other) noexcept
{
	ASprite::operator=(other);
	if (this != &other) {
		this->_sprite = other._sprite;
		this->_texture = other._texture;
		this->_sizeTileX = other._sizeTileX;
		this->_sizeTileY = other._sizeTileY;
		this->_animationVector = other._animationVector;
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

void	SpriteSFML::setAnimationVector(const std::vector<sf::Texture>
					   &vector, bool repeat) noexcept
{
	this->_animationVector = vector;
	this->_repeatAnimation = repeat;
}

/**
 * Set next texture to draw
 * If more than one animation and didnt played all animations
 * If animation finished and animation has to be repeated, restart Animation
 * else set a black rectangle
 */
void	SpriteSFML::updateAnimation() noexcept
{
	if (!this->_animationVector.empty() &&
	    this->_animationIndex < this->_animationVector.size()) {
		this->_sprite.setTexture(_animationVector[_animationIndex],
					 true);
		++this->_animationIndex;
		if (this->_animationIndex >= this->_animationVector.size()
		    && this->_repeatAnimation) {
			this->_animationIndex = 0;
		}
	} else {
		this->_waitingToBeDeleted = true;
	}
}

void SpriteSFML::setPosX(int x) noexcept
{
	ASprite::setPosX(x);
	this->_sprite.setOrigin(x, this->_posY);
}

void SpriteSFML::setPosY(int y) noexcept
{
	ASprite::setPosY(y);
	this->_sprite.setOrigin(this->_posX, y);
}

void SpriteSFML::setPos(int x, int y) noexcept
{
	ASprite::setPos(x, y);
	this->_sprite.setOrigin(x, y);
}
