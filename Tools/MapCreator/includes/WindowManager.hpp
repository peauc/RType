/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_WINDOWMANAGER_HPP
#define MAPCREATOR_WINDOWMANAGER_HPP

#include <chrono>
#include "IWindow.hpp"
#include "GridLayout.hpp"
#include "ListView.hpp"

class MapView;

class WindowManager : public AItem, public IWindow {

public:

	WindowManager();
	~WindowManager() = default;
	WindowManager(const WindowManager&) = delete;
	WindowManager    operator=(const WindowManager&) = delete;

	void	start();

	void	setEnemiesDirectory(const std::string &enemiesDirectory);
	void	setBackgroundsDirectory(const std::string &backgroundsDirectory);
	void	setOutputDirectory(const std::string &outputDirectory);
	void	setExistingMap(const std::string &existingMap);


protected:

	virtual void	onClosed(const sf::Event &event);
	virtual void	onResized(const sf::Event &event);
	virtual void	onLostFocus(const sf::Event &event);
	virtual void	onGainedFocus(const sf::Event &event);
	virtual void	onKeyPressed(const sf::Event &event);
	virtual void	onKeyReleased(const sf::Event &event);
	virtual void	onMouseEntered(const sf::Event &event);
	virtual void	onMouseLeft(const sf::Event &event);

	virtual void	displayOnWindow(sf::RenderWindow &window);
	virtual void	associateEvents();
	virtual void	receiveEvent(const sf::Event &event);
	virtual void	refresh();

	virtual void	init();

private:

	bool		needRefresh();
	void		fillGridView();
	MapView 	*addMapView();
	void		addEnemiesList(MapView *mapView);
	void 		addBackgroundsList(MapView *mapView);

	sf::RenderWindow	window;
	GridLayout			gridLayout;

	std::string			enemiesDirectory;
	std::string			backgroundsDirectory;
	std::string			outputDirectory;
	std::string			existingMap;

	std::chrono::time_point<std::chrono::system_clock> timePoint;
	std::chrono::time_point<std::chrono::system_clock> currentTime;

};


#endif //MAPCREATOR_WINDOWMANAGER_HPP
