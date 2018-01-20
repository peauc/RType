/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <utility>
#include "Graphic/MenuSFML.hpp"

MenuSFML::MenuSFML(std::vector<const ISprite*> sprites) noexcept
 : _sprites(std::move(sprites))
{
}

std::vector<const ISprite*>	&MenuSFML::getSpritesToDraw() noexcept
{
	return (_sprites);
}

void	MenuSFML::addSprite(const ISprite *sprite) noexcept
{
	this->_sprites.push_back(sprite);
}

std::vector<const IText*> &MenuSFML::getTextsToDraw() noexcept
{
	return (_texts);
}

void MenuSFML::addText(const IText *text) noexcept
{
	this->_texts.push_back(text);
}
