/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_WINDOWMANAGER_HPP
#define MAPCREATOR_WINDOWMANAGER_HPP

#include <IWindow.hpp>

class WindowManager : public IWindow {

public:

	WindowManager();
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
	virtual void	onMouseMoved(const sf::Event &event);
	virtual void	onMouseEntered(const sf::Event &event);
	virtual void	onMouseLeft(const sf::Event &event);

private:

	sf::RenderWindow	window;

};


#endif //MAPCREATOR_WINDOWMANAGER_HPP
