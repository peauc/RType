/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include "Graphic/BackgroundSFML.hpp"

BackgroundSFML::BackgroundSFML(const std::string &fileName, int width,
			       int height, float speedX, float speedY)
 : SpriteSFML(fileName, 0, 0), _width(width), _height(height),
   _speedX(speedX), _speedY(speedY)
{
	this->_texture.setRepeated(true);
	this->_sprite.setTextureRect(sf::IntRect(0, 0, 1920 * 2, 1080 * 2));
}


void BackgroundSFML::updateAnimation() noexcept
{
	this->_sprite.move(-this->_speedX, -this->_speedY);
	if (this->_sprite.getPosition().x <= -_width ||
		this->_sprite.getPosition().x >= _width) {
		this->_sprite.setPosition(0, this->_sprite.getPosition().y);
	}
	if (this->_sprite.getPosition().y <= -_height ||
	    this->_sprite.getPosition().y >= _height) {
		this->_sprite.setPosition(this->_sprite.getPosition().x, 0);
	}
}

float BackgroundSFML::getSpeedX() const noexcept
{
	return (this->_speedX);
}

float BackgroundSFML::getSpeedY() const noexcept
{
	return (this->_speedY);
}

void BackgroundSFML::setSpeed(float x, float y) noexcept
{
	this->_speedX = x;
	this->_speedY = y;
}