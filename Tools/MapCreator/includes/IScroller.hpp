/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_ISCROLLER_HPP
#define MAPCREATOR_ISCROLLER_HPP

#include <SFML/Graphics.hpp>

class IScroller {

protected:

	virtual void	onMouseWheelScrolled(const sf::Event &event) = 0;

};

#endif //MAPCREATOR_ISCROLLER_HPP
