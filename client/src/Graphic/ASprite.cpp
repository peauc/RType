/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include "Graphic/ASprite.hpp"

ASprite::ASprite() noexcept
 : _posX(0), _posY(0), _animationId(0), _animationIndex(0),
   _repeatAnimation(true), _waitingToBeDeleted(false),
   _display(true), _onClick(nullptr)
{
}

ASprite::ASprite(const ASprite &other) noexcept
{
	if (this != &other) {
		this->_posX = other._posX;
		this->_posY = other._posY;
		this->_animationId = other._animationId;
		this->_animationIndex = other._animationIndex;
		this->_repeatAnimation = other._repeatAnimation;
		this->_waitingToBeDeleted = other._waitingToBeDeleted;
		this->_display = other._display;
		this->_onClick = other._onClick;
	}
}

ASprite &ASprite::operator=(const ASprite &other) noexcept
{
	if (this != &other) {
		this->_posX = other._posX;
		this->_posY = other._posY;
		this->_animationId = other._animationId;
		this->_animationIndex = other._animationIndex;
		this->_repeatAnimation = other._repeatAnimation;
		this->_waitingToBeDeleted = other._waitingToBeDeleted;
		this->_display = other._display;
		this->_onClick = other._onClick;
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

void ASprite::onClick()
{
	if (this->_onClick) {
		this->_onClick();
	}
}

void ASprite::setOnClick(std::function<void()> f) noexcept
{
	this->_onClick = f;
}

void ASprite::setPos(int x, int y) noexcept
{
	this->_posX = x;
	this->_posY = y;
}

uint32_t ASprite::getAnimationId() const noexcept
{
	return (this->_animationId);
}

void ASprite::setAnimationId(uint32_t id) noexcept
{
	this->_animationId = id;
}

bool ASprite::isWaitingToBeDeleted() const noexcept
{
	return (this->_waitingToBeDeleted);
}

bool ASprite::isAnimationRepeating() const noexcept
{
	return (this->_repeatAnimation);
}

void ASprite::setRepeatAnimation(bool repeat) noexcept
{
	this->_repeatAnimation =repeat;
}

bool ASprite::isDisplay() const
{
	return (this->_display);
}

void ASprite::setDisplay(bool display)
{
	this->_display = display;
}
