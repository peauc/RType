/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_ASPRITEBACKGROUND_HPP
#define MAPCREATOR_ASPRITEBACKGROUND_HPP

#include "ASpriteItem.hpp"

class ASpriteBackground : public ASpriteItem {

public:

	ASpriteBackground(AItem *parent = nullptr);
	~ASpriteBackground() = default;
	ASpriteBackground(const ASpriteBackground&) = delete;
	ASpriteBackground	&operator=(const ASpriteBackground&) = delete;

	virtual void	refresh();
	virtual void	displayOnlyInParentBounds();

};

#endif //MAPCREATOR_ASPRITEBACKGROUND_HPP
