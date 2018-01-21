/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_LISTVIEW_HPP
#define MAPCREATOR_LISTVIEW_HPP

#include "AModel.hpp"
#include "AContainer.hpp"
#include "AScroller.hpp"

class ListView : public AContainer, public AScroller {

public:

	ListView(Scroll scroll = VERTICAL, AItem *parent = nullptr);
	~ListView() = default;
	ListView(const ListView &) = delete;
	ListView	&operator=(const ListView &obj) = delete;

	virtual void	displayOnWindow(sf::RenderWindow &window);
	virtual void	associateEvents();
	virtual void	receiveEvent(const sf::Event &event);
	virtual void	refresh();

	virtual void	onMouseWheelScrolled(const sf::Event &event);

	virtual void	addChild(AItem *child);

	void	setModel(AModel *model);

protected:

	std::unique_ptr<AModel>		model;
	int								childWidth;
	int 							childHeight;

private:

	void	formatChilds();
	void	setChildsSize();

};


#endif //MAPCREATOR_LISTVIEW_HPP
