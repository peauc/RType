/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_CHILDMAP_HPP
#define MAPCREATOR_CHILDMAP_HPP

#include "ASpriteBackground.hpp"
#include "IDragAndDrop.hpp"
#include "AContainer.hpp"

class DuplicableItem;

class ChildMap : public ASpriteBackground, public IDragAndDrop {

public:

	ChildMap(AItem *parent = nullptr);
	virtual ~ChildMap() = default;
	ChildMap(const ChildMap &obj);
	ChildMap	&operator=(const ChildMap&) = delete;

	ChildMap(const DuplicableItem &obj);

	virtual void	displayOnWindow(sf::RenderWindow &window);
	virtual void	associateEvents();
	virtual void	receiveEvent(const sf::Event &event);
	virtual void	refresh();
	virtual void	displayOnlyInParentBounds();

	virtual void	onMouseButtonPressed(const sf::Event &event);
	virtual void	onMouseButtonReleased(const sf::Event &event);
	virtual void	onMouseMoved(const sf::Event &event);

	void			setScrollValue(int scrollValue);
	int				getScrollValue() const;

	const std::string	&getPathItem() const;

	bool			isResizing();
	void 			setResizing(bool state);

protected:

	std::string		pathItem;
	int				scrollValue;
	bool			selected;
	bool			resizing;

};

#endif //MAPCREATOR_CHILDMAP_HPP
