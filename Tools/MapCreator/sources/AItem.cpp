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
	this->background.setFillColor(sf::Color::Transparent);
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

void AItem::setX(int x) {
	this->x = x;
	this->backgroundFillAItem();
}

void AItem::setY(int y) {
	this->y = y;
	this->backgroundFillAItem();
}

void AItem::setWidth(int width) {
	this->width = width;
	this->backgroundFillAItem();
}

void AItem::setHeight(int height) {
	this->height = height;
	this->backgroundFillAItem();
}

int AItem::getX() const {
	return (this->x);
}

int AItem::getY() const {
	return (this->y);
}

int AItem::getWidth() const {
	return (this->width);
}

int AItem::getHeight() const {
	return (this->height);
}

void AItem::backgroundFillAItem() {
	this->background.setPosition(this->x, this->y);
	this->background.setSize(sf::Vector2f(this->width, this->height));
}

void AItem::fillParent() {
	if (this->parent) {
		this->x = this->parent->x;
		this->y = this->parent->y;
		this->width = this->parent->width;
		this->height = this->parent->height;
		this->backgroundFillAItem();
	}
}

void AItem::fillParentWidth() {
	if (this->parent) {
		this->x = this->parent->x;
		this->width = this->parent->width;
		this->backgroundFillAItem();
	}
}

void AItem::fillParentHeight() {
	if (this->parent) {
		this->y = this->parent->y;
		this->height = this->parent->height;
		this->backgroundFillAItem();
	}
}

bool AItem::inBounds(int x, int y) const {
	return (x >= this->x && x <= (this->x + this->width - 1)
			&& y >= this->y && y <= (this->y + this->height - 1));
}
