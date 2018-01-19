/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "AItem.hpp"

AItem::AItem(AItem *parent) {
	this->parent = parent;
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
	this->background.setFillColor(sf::Color(255, 255, 255, 255));
	this->backgroundFillAItem();
	for (auto &action : this->actionsEvent)
		action = nullptr;
	for (auto &action : this->actionsKey)
		action = nullptr;
}

AItem::AItem(const AItem &obj) {
	this->parent = obj.parent;
	this->x = obj.x;
	this->y = obj.y;
	this->width = obj.width;
	this->height = obj.height;
	this->background = obj.background;
	this->actionsEvent = obj.actionsEvent;
	this->actionsKey = obj.actionsKey;
}

AItem &AItem::operator=(const AItem &obj) {
	if (&obj != this) {
		this->parent = obj.parent;
		this->x = obj.x;
		this->y = obj.y;
		this->width = obj.width;
		this->height = obj.height;
		this->background = obj.background;
		this->actionsEvent = obj.actionsEvent;
		this->actionsKey = obj.actionsKey;
	}
	return (*this);
}

void AItem::setParent(AItem *parent) {
	this->parent = parent;
}

void AItem::setX(unsigned int x) {
	if (this->parent && x >= this->parent->x
		&& x <= (this->parent->x + (this->parent->width - 1)))
		this->x = x;
	else if (!this->parent)
		this->x = x;
}

void AItem::setY(unsigned int y) {
	if (this->parent && y >= this->parent->y
		&& y <= (this->parent->y + (this->parent->height - 1)))
		this->y = y;
	else if (!this->parent)
		this->y = y;
}

void AItem::setWidth(unsigned int width) {
	if (this->parent && (this->x + width - 1)
						<= (this->parent->x + this->parent->width - 1))
		this->width = width;
	else if (!this->parent)
		this->width = width;
}

void AItem::setHeight(unsigned int height) {
	if (this->parent && (this->y + height - 1)
						<= (this->parent->y + this->parent->height - 1))
		this->height = height;
	else if (!this->parent)
		this->height = height;
}

unsigned int AItem::getX() const {
	return (this->x);
}

unsigned int AItem::getY() const {
	return (this->y);
}

unsigned int AItem::getWidth() const {
	return (this->width);
}

unsigned int AItem::getHeight() const {
	return (this->height);
}

void AItem::displayOnWindow(sf::RenderWindow &window) {
	window.draw(background);
}

void AItem::receiveEvent(const sf::Event &event) {

}

void AItem::backgroundFillAItem() {
	this->background.setPosition(this->x, this->y);
	this->background.setSize(sf::Vector2f(this->width, this->height));
}
