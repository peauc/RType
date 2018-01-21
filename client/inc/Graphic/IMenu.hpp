/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_IMENU_HPP
# define RTYPE_IMENU_HPP

#include <memory>
#include "Graphic/ISprite.hpp"
#include "Graphic/IText.hpp"

class	IMenu
{
public:
	virtual ~IMenu() = default;
	
	virtual const std::vector<std::unique_ptr<ISprite>>
		&getSpritesToDraw() const = 0;
	virtual const std::vector<std::unique_ptr<IText>>
		&getTextsToDraw() const = 0;
	virtual void		addSprite(std::unique_ptr<ISprite> sprite) = 0;
	virtual void		addText(std::unique_ptr<IText> text) = 0;
};

#endif //RTYPE_IMENU_HPP
