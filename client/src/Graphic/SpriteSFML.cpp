/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <iostream>
#include "Graphic/SpriteSFML.hpp"

SpriteSFML::SpriteSFML() noexcept
	: _sizeTileX(0), _sizeTileY(0),
	  _animationIndex(0), _repeatAnimation(false)
{
}

SpriteSFML::SpriteSFML(const std::string &fileName,
		       unsigned int sizeTileX, unsigned int sizeTileY)
 : _sizeTileX(sizeTileX), _sizeTileY(sizeTileY), _animationIndex(0)
{
	if (!this->_texture.loadFromFile(fileName)) {
		throw std::runtime_error("Cannot open file : " + fileName);
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
		this->_animationIndex = other._animationIndex;
		this->_repeatAnimation = other._repeatAnimation;
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
		this->_animationIndex = other._animationIndex;
		this->_repeatAnimation = other._repeatAnimation;
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
	bool	equal = true;

	if (vector.size() == this->_animationVector.size() &&
		vector.size() > 1) {
		for (int i = 0;
		     i < vector.size() && i < this->_animationVector.size();
		     ++i) {
			if (&vector[i] != &this->_animationVector[i]) {
				equal = false;
				break;
			}
		}
	} else {
		equal = false;
	}
	if (!equal) {
		this->_animationVector = vector;
		this->_repeatAnimation = repeat;
	}
}

/**
 * Set next texture to draw
 */
void	SpriteSFML::updateAnimation() noexcept
{
	if (this->_animationVector.size() > 1 &&
	    this->_animationIndex < this->_animationVector.size()) {
		this->_sprite.setTexture(_animationVector[_animationIndex],
					 true);
		++this->_animationIndex;
		if (this->_animationIndex >= this->_animationVector.size()
		    && this->_repeatAnimation) {
			this->_animationIndex = 0;
		}
	} else {
		this->_sprite.setTextureRect(sf::IntRect());
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
