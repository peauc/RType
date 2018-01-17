/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include "ASprite.hpp"

ASprite::ASprite() noexcept
 : _posX(0), _posY(0)
{
}

ASprite::ASprite(const ASprite &other) noexcept
{
	if (this != &other) {
		this->_posX = other._posX;
		this->_posY = other._posY;
	}
}

ASprite &ASprite::operator=(const ASprite &other) noexcept
{
	if (this != &other) {
		this->_posX = other._posX;
		this->_posY = other._posY;
	}
	return (*this);
}

int	ASprite::getPosX() const noexcept
{
	return (this->_posX);
}

int	ASprite::getPosY() const noexcept
{
	return (this->_posY);
}

void ASprite::setPosX(int x) noexcept
{
	this->_posX = x;
}

void ASprite::setPosY(int y) noexcept
{
	this->_posY = y;
}
