/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_ASPRITEINLIST_HPP
#define MAPCREATOR_ASPRITEINLIST_HPP

#include "ASpriteItem.hpp"

class ASpriteInList : public ASpriteItem {

public:

	ASpriteInList(AItem *parent = nullptr);
	~ASpriteInList() = default;
	ASpriteInList(const ASpriteInList &obj);
	ASpriteInList	&operator=(const ASpriteInList&) = delete;

	virtual void	refresh();
	virtual void	displayOnlyInParentBounds();

};


#endif //MAPCREATOR_ASPRITEINLIST_HPP
