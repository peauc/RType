/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "MapBackgroundItem.hpp"

MapBackgroundItem::MapBackgroundItem(const std::string &iconPath,
									 AItem *parent, AContainer *employer)
		: ASpriteInList(parent) {
	this->texture.loadFromFile(iconPath);
	this->icon.setTexture(this->texture, true);
	this->employer = employer;
	this->associateEvents();
}

void MapBackgroundItem::displayOnWindow(sf::RenderWindow &window) {
	window.draw(this->icon);
}

void MapBackgroundItem::associateEvents() {
	this->actionsEvent[sf::Event::MouseButtonPressed] =
			static_cast<AItem::Callback>
			(&MapBackgroundItem::onMouseButtonPressed);
	this->actionsEvent[sf::Event::MouseButtonReleased] =
			static_cast<AItem::Callback>
			(&MapBackgroundItem::onMouseButtonReleased);
}

void MapBackgroundItem::receiveEvent(const sf::Event &event) {
	if (this->actionsEvent[event.type])
		(this->*(this->actionsEvent[event.type]))(event);
}

void MapBackgroundItem::refresh() {
	ASpriteInList::refresh();
}

void MapBackgroundItem::onMouseButtonPressed(const sf::Event &event) {
	if (this->inBounds(event.mouseButton.x, event.mouseButton.y)) {
		if (this->employer)
			this->employer->lendBackgroundTexture(this->texture);
	}
}

void MapBackgroundItem::onMouseButtonReleased(const sf::Event &event) {

}

void MapBackgroundItem::onMouseMoved(const sf::Event &event) {

}
