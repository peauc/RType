/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_MAPVIEW_HPP
#define MAPCREATOR_MAPVIEW_HPP

#include "SpriteBackground.hpp"
#include "AListModel.hpp"
#include "AContainer.hpp"
#include "AScroller.hpp"

class MapView : public AContainer, public AScroller {

public:

	MapView(Scroll scroll = VERTICAL, AItem *parent = nullptr);
	~MapView() = default;
	MapView(const MapView &) = delete;
	MapView	&operator=(const MapView &obj) = delete;

	virtual void	displayOnWindow(sf::RenderWindow &window);
	virtual void	associateEvents();
	virtual void	receiveEvent(const sf::Event &event);
	virtual void	refresh();

	virtual void	onMouseWheelScrolled(const sf::Event &event);

	virtual void	addChild(AItem *child);

	void	setModel(AListModel *model);

	virtual void	lendBackgroundTexture(sf::Texture &texture);

protected:

	std::unique_ptr<AListModel>		model;
	SpriteBackground				spriteBackground;

};

#endif //MAPCREATOR_MAPVIEW_HPP
