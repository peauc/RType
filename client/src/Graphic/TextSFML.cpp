/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include "Graphic/TextSFML.hpp"

TextSFML::TextSFML(const std::string &font,
		   const std::string &text,
		   uint32_t charSize) noexcept
 : AText(text)
{
	this->_sText.setString(text);
	this->setCharSize(charSize);
	this->setFont(font);
}

TextSFML::TextSFML(const TextSFML &other) noexcept
 : AText(other)
{
	if (this != &other) {
		this->_sText = other._sText;
	}
}

TextSFML &TextSFML::operator=(const TextSFML &other) noexcept
{
	AText::operator=(other);
	if (this != &other) {
		this->_sText = other._sText;
	}
	return (*this);
}

void TextSFML::setText(const std::string &text) noexcept
{
	AText::setText(text);
	this->_sText.setString(text);
}

const	std::string &TextSFML::getText() const noexcept
{
	return AText::getText();
}

void	TextSFML::setFont(const std::string &font)
{
	if (!this->_font.loadFromFile(font)) {
		throw std::runtime_error("Cannot open file : " + font);
	}
	this->_sText.setFont(this->_font);
}

void	TextSFML::setCharSize(uint32_t charSize) noexcept
{
	this->_sText.setCharacterSize(charSize);
}

const	sf::Text &TextSFML::getSText() const noexcept
{
	return (this->_sText);
}

void TextSFML::setPosX(int x) noexcept
{
	AText::setPosX(x);
	this->_sText.setPosition(x, this->_y);
}

void TextSFML::setPosY(int y) noexcept
{
	AText::setPosY(y);
	this->_sText.setPosition(this->_x, y);
}

void TextSFML::setPos(int x, int y) noexcept
{
	AText::setPos(x, y);
	this->_sText.setPosition(x, y);
}
