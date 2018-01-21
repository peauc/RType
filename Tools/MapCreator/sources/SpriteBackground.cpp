/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "SpriteBackground.hpp"

SpriteBackground::SpriteBackground(AItem *parent) : ASpriteBackground(parent) {
	this->associateEvents();
}

void SpriteBackground::displayOnWindow(sf::RenderWindow &window) {
	window.draw(this->icon);
}

void SpriteBackground::associateEvents() {

}

void SpriteBackground::receiveEvent(const sf::Event &event) {

}

void SpriteBackground::refresh() {
	ASpriteBackground::refresh();
}

void SpriteBackground::setTexture(sf::Texture &texture) {
	this->fillParent();
	this->texture = texture;
	this->icon.setTexture(this->texture, true);
	this->icon.setPosition(this->getX(), this->getY());
	ASpriteBackground::refresh();
}
