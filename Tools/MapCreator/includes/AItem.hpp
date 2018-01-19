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

	void	setX(unsigned int x);
	void	setY(unsigned int y);
	void	setWidth(unsigned int width);
	void	setHeight(unsigned int height);

	unsigned int	getX() const;
	unsigned int	getY() const;
	unsigned int	getWidth() const;
	unsigned int	getHeight() const;

	virtual void	displayOnWindow(sf::RenderWindow &window) = 0;
	virtual void	associateEvents() = 0;
	virtual void	receiveEvent(const sf::Event &event) = 0;

protected:

	AItem				*parent;
	unsigned int		x;
	unsigned int		y;
	unsigned int		width;
	unsigned int		height;
	sf::RectangleShape	background;

	using Callback = void (AItem::*) (const sf::Event &event);

	std::array<AItem::Callback, sf::Event::Count>		actionsEvent;
	std::array<AItem::Callback, sf::Keyboard::KeyCount>	actionsKey;

private:

	void	backgroundFillAItem();
};


#endif //MAPCREATOR_AITEM_HPP
