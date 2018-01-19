/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_IWINDOW_HPP
#define MAPCREATOR_IWINDOW_HPP

#include <SFML/Graphics.hpp>

class IWindow {

protected:

	virtual void	onClosed(const sf::Event &event) = 0;
	virtual void	onResized(const sf::Event &event) = 0;
	virtual void	onLostFocus(const sf::Event &event) = 0;
	virtual void	onGainedFocus(const sf::Event &event) = 0;
	virtual void	onKeyPressed(const sf::Event &event) = 0;
	virtual void	onKeyReleased(const sf::Event &event) = 0;
	virtual void	onMouseMoved(const sf::Event &event) = 0;
	virtual void	onMouseEntered(const sf::Event &event) = 0;
	virtual void	onMouseLeft(const sf::Event &event) = 0;

};

#endif //MAPCREATOR_IWINDOW_HPP
