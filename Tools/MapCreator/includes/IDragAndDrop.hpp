/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_IDRAGANDDROP_HPP
#define MAPCREATOR_IDRAGANDDROP_HPP

#include <SFML/Graphics.hpp>

class IDragAndDrop {

protected:

	virtual void	onMouseButtonPressed(const sf::Event &event) = 0;
	virtual void	onMouseButtonReleased(const sf::Event &event) = 0;

};

#endif //MAPCREATOR_IDRAGANDDROP_HPP
