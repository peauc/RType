/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_MAPVIEW_HPP
#define MAPCREATOR_MAPVIEW_HPP

#include "SpriteBackground.hpp"
#include "MapModel.hpp"
#include "AContainer.hpp"
#include "AScroller.hpp"

class MapModel;

class MapView : public AContainer, public AScroller, public IDragAndDrop {

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
	virtual void	onMouseButtonPressed(const sf::Event &event);
	virtual void	onMouseButtonReleased(const sf::Event &event);
	virtual void	onMouseMoved(const sf::Event &event);
	virtual void	onKeyPressed(const sf::Event &event);

	virtual void	addChild(AItem *child);
	void			loadChild(AItem *child);

	void			setModel(MapModel *model);

	virtual void	lendBackgroundTexture(sf::Texture &texture);

	int				getScrollValue() const;

protected:

	unsigned int	getPotentialTriggeredChild(int x, int y);

	std::unique_ptr<MapModel>		model;
	SpriteBackground				spriteBackground;
	bool 							scrollable;

private:

	void	resizeChild(const sf::Event &event);
	void	changeSize(unsigned int childIndex, int newWidth, int newHeight);
	void	createZone(const sf::Event &event);
	void	sortChilds();
	bool	onExistingZone(const sf::Event &event);

	int		lastMouseX;
	int 	lastMouseY;

};

#endif //MAPCREATOR_MAPVIEW_HPP
