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

class WindowManager : public AItem, public IWindow {

public:

	WindowManager(const std::string &enemiesDirectory,
				  const std::string &backgroundsDirectory,
				  const std::string &dest);
	~WindowManager() = default;
	WindowManager(const WindowManager&) = delete;
	WindowManager    operator=(const WindowManager&) = delete;

	void	start();

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

private:

	bool	needRefresh();
	void	fillGridView(const std::string &enemiesDirectory,
						 const std::string &backgroundsDirectory,
						 const std::string &dest);

	sf::RenderWindow	window;
	GridLayout			gridLayout;

	std::chrono::time_point<std::chrono::system_clock> timePoint;
	std::chrono::time_point<std::chrono::system_clock> currentTime;

};


#endif //MAPCREATOR_WINDOWMANAGER_HPP
