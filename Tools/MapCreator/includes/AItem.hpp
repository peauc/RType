/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_AITEM_HPP
#define MAPCREATOR_AITEM_HPP

#include <SFML/Graphics.hpp>
#include <array>

class AItem {

public:

	AItem(AItem *parent = nullptr);
	virtual ~AItem() = default;
	AItem(const AItem &obj);
	AItem    &operator=(const AItem &obj);

	void	setParent(AItem *parent);

	void	setX(int x);
	void	setY(int y);
	void	setWidth(int width);
	void	setHeight(int height);

	int				getX() const;
	int				getY() const;
	int				getWidth() const;
	int				getHeight() const;

	void			fillParent();
	void			fillParentWidth();
	void			fillParentHeight();

	virtual void	displayOnWindow(sf::RenderWindow &window) = 0;
	virtual void	associateEvents() = 0;
	virtual void	receiveEvent(const sf::Event &event) = 0;
	virtual void	refresh() = 0;

	bool	inBounds(int x, int y) const;

protected:

	AItem				*parent;
	sf::RectangleShape	background;

	void	backgroundFillAItem();

	using Callback = void (AItem::*) (const sf::Event &event);

	std::array<AItem::Callback, sf::Event::Count>		actionsEvent;
	std::array<AItem::Callback, sf::Keyboard::KeyCount>	actionsKey;

private:

	int		x;
	int		y;
	int		width;
	int		height;
};


#endif //MAPCREATOR_AITEM_HPP
