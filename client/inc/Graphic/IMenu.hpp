/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_IMENU_HPP
# define RTYPE_IMENU_HPP

#include "Graphic/ISprite.hpp"
#include "Graphic/IText.hpp"

class	IMenu
{
public:
	virtual ~IMenu() = default;
	
	virtual std::vector<const ISprite*>	&getSpritesToDraw() = 0;
	virtual std::vector<const IText*>	&getTextsToDraw() = 0;
	virtual void		addSprite(const ISprite *sprite) = 0;
	virtual void		addText(const IText *text) = 0;


};

#endif //RTYPE_IMENU_HPP
