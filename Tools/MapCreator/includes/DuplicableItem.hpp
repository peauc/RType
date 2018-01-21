/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_DUPLICABLEITEM_HPP
#define MAPCREATOR_DUPLICABLEITEM_HPP

#include "ASpriteInList.hpp"
#include "IDragAndDrop.hpp"
#include "AContainer.hpp"

class DuplicableItem : public ASpriteInList, public IDragAndDrop {

public:

	DuplicableItem(const std::string &iconPath, AItem *parent = nullptr,
				   AContainer *employer = nullptr);
	virtual ~DuplicableItem() = default;
	DuplicableItem(const DuplicableItem &obj);
	DuplicableItem	&operator=(const DuplicableItem&) = delete;

	virtual void	displayOnWindow(sf::RenderWindow &window);
	virtual void	associateEvents();
	virtual void	receiveEvent(const sf::Event &event);
	virtual void	refresh();

	virtual void	onMouseButtonPressed(const sf::Event &event);
	virtual void	onMouseButtonReleased(const sf::Event &event);
	virtual void	onMouseMoved(const sf::Event &event);

	void			setXOnDuplicate(int value);
	void			setYOnDuplicate(int value);
	void			setScrollOnDuplicate(int value);
	int				getXOnDuplicate();
	int				getYOnDuplicate();
	int				getScrollOnDuplicate();

protected:

	AContainer		*employer;
	std::string		pathItem;
	int				xOnDuplicate;
	int 			yOnDuplicate;
	int 			scrollOnDuplicate;
	bool			selected;

};


#endif //MAPCREATOR_DUPLICABLEITEM_HPP
