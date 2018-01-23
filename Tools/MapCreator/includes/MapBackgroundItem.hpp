/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_MAPBACKGROUNDITEM_HPP
#define MAPCREATOR_MAPBACKGROUNDITEM_HPP

#include "ASpriteInList.hpp"
#include "IDragAndDrop.hpp"
#include "AContainer.hpp"

class MapBackgroundItem : public ASpriteInList, public IDragAndDrop {

public:

	MapBackgroundItem(const std::string &iconPath, AItem *parent,
					  AContainer *employer);
	virtual ~MapBackgroundItem() = default;
	MapBackgroundItem(const MapBackgroundItem&) = delete;
	MapBackgroundItem	&operator=(const MapBackgroundItem&) = delete;

	virtual void	displayOnWindow(sf::RenderWindow &window);
	virtual void	associateEvents();
	virtual void	receiveEvent(const sf::Event &event);
	virtual void	refresh();

	virtual void	init();

	virtual void	onMouseButtonPressed(const sf::Event &event);
	virtual void	onMouseButtonReleased(const sf::Event &event);
	virtual void	onMouseMoved(const sf::Event &event);

protected:

	AContainer	*employer;

};


#endif //MAPCREATOR_MAPBACKGROUNDITEM_HPP
