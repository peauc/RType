/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <Graphic/AText.hpp>

AText::AText(const std::string &text) noexcept
 : _text(text)
{
}

AText::AText(const AText &other) noexcept
{
	if (this != &other) {
		this->_text = other._text;
	}
}

AText &AText::operator=(const AText &other) noexcept
{
	if (this != &other) {
		this->_text = other._text;
	}
	return (*this);
}

void	AText::setText(const std::string &text) noexcept
{
	this->_text = text;
}

const	std::string &AText::getText() const noexcept
{
	return (this->_text);
}

void	AText::setPosX(int x) noexcept
{
	this->_x = x;
}

void	AText::setPosY(int y) noexcept
{
	this->_y = y;
}

int	AText::getPosX() const noexcept
{
	return (this->_x);
}

int	AText::getPosY() const noexcept
{
	return (this->_y);
}
