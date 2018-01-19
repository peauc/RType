/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "GridView.hpp"

GridView::GridView(WindowManager &parent) : AItem(this), parent(parent) {
//	this->actionsKey[sf::Keyboard::Right] =
//			static_cast<AItem::Callback>(&GridView::onMouseWheelScrolled);
//	sf::Event event;
//	(this->*(this->actionsKey[sf::Keyboard::Right]))(event);
}

void GridView::displayOnWindow(sf::RenderWindow &window) {

}

void GridView::receiveEvent(const sf::Event &event) {

}

void GridView::associateEvents() {

}
