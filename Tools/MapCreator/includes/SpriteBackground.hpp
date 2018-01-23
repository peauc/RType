/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_SPRITEBACKGROUND_HPP
#define MAPCREATOR_SPRITEBACKGROUND_HPP

#include "ASpriteBackground.hpp"
#include "IDragAndDrop.hpp"

class SpriteBackground : public ASpriteBackground {

public:

	SpriteBackground(AItem *parent = nullptr);
	virtual ~SpriteBackground() = default;
	SpriteBackground(const SpriteBackground&) = delete;
	SpriteBackground	&operator=(const SpriteBackground&) = delete;

	virtual void	displayOnWindow(sf::RenderWindow &window);
	virtual void	associateEvents();
	virtual void	receiveEvent(const sf::Event &event);
	virtual void	refresh();

	virtual void	init();

	void		setTexture(sf::Texture &texture);

};

#endif //MAPCREATOR_SPRITEBACKGROUND_HPP
