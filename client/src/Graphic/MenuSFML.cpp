/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <utility>
#include "Graphic/MenuSFML.hpp"

const std::vector<std::unique_ptr<ISprite>> &MenuSFML::getSpritesToDraw() const noexcept
{
	return (_sprites);
}

void	MenuSFML::addSprite(std::unique_ptr<ISprite> sprite) noexcept
{
	this->_sprites.push_back(std::move(sprite));
}

const std::vector<std::unique_ptr<IText>> &MenuSFML::getTextsToDraw() const noexcept
{
	return (_texts);
}
void MenuSFML::addText(std::unique_ptr<IText> text) noexcept
{
	this->_texts.push_back(std::move(text));
}
