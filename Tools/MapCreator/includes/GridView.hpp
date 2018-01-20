/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_GRIDVIEW_HPP
#define MAPCREATOR_GRIDVIEW_HPP

#include "AItem.hpp"

class WindowManager;

class GridView : public AItem {

public:

	GridView(WindowManager &parent);
	~GridView() = default;
	GridView(const GridView&) = delete;
	GridView	&operator=(const GridView&) = delete;

	virtual void	displayOnWindow(sf::RenderWindow &window);
	virtual void	receiveEvent(const sf::Event &event);
	virtual void	associateEvents();

private:

	WindowManager	&parent;
};


#endif //MAPCREATOR_GRIDVIEW_HPP
