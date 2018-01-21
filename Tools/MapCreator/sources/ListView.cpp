/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "ListView.hpp"

ListView::ListView(Scroll scroll, AItem *parent) : AContainer(parent) {
	this->scroll = scroll;
	this->maxScroll = 0;
	this->scrollSpeed = 10;
	this->scrollValue = 0;
	this->childMarginTop = 15;
	this->childMarginBot = 15;
	this->childMarginLeft = 30;
	this->childMarginRight = 30;
	this->background.setFillColor(sf::Color(84, 110, 122, 255));
	this->associateEvents();
}

void ListView::displayOnWindow(sf::RenderWindow &window) {
	window.draw(this->background);
	for (auto &child : this->childs)
		child->displayOnWindow(window);
}

void ListView::associateEvents() {
	this->actionsEvent[sf::Event::MouseWheelScrolled] =
			static_cast<AItem::Callback>(&ListView::onMouseWheelScrolled);
}

void ListView::receiveEvent(const sf::Event &event) {
	if (this->actionsEvent[event.type])
		(this->*(this->actionsEvent[event.type]))(event);
	for (auto &child : this->childs)
		child->receiveEvent(event);
}

void ListView::refresh() {
	this->setChildsSize();
	this->formatChilds();
	for (auto &child : this->childs)
		child->refresh();
}

void ListView::addChild(AItem *child) {
	child->setWidth(this->childWidth);
	child->setHeight(this->childHeight);
	AContainer::addChild(child);
}

void ListView::setModel(AModel *model) {
	this->model.reset(model);
	this->model->loadDataModel();
}

void ListView::onMouseWheelScrolled(const sf::Event &event) {
	int		newScrollValue;

	if (this->inBounds(event.mouseWheelScroll.x, event.mouseWheelScroll.y)) {
		newScrollValue = static_cast<int>(this->scrollValue
										  + event.mouseWheelScroll.delta
											* this->scrollSpeed);
		if (newScrollValue > -(this->maxScroll) && newScrollValue < 0)
			this->scrollValue = newScrollValue;
		else if (newScrollValue >= 0)
			this->scrollValue = 0;
		this->refresh();
	}
}

void ListView::formatChilds() {
	unsigned int	index = 0;

	for (auto &child : this->childs) {
		child->setX(this->getX());
		child->setY(this->getY());
		child->setWidth(this->childWidth);
		child->setHeight(this->childHeight);
		if (this->scroll == HORIZONTAL) {
			child->setX(this->getX()
						+ ((child->getWidth() + this->childMarginLeft) * index)
						+ this->scrollValue);
		} else if (this->scroll == VERTICAL) {
			child->setY(this->getY()
						+ ((child->getHeight() + this->childMarginTop) * index)
						+ this->scrollValue);
		}
		++index;
	}
}

void ListView::setChildsSize() {
	if (this->scroll == HORIZONTAL) {
		this->childWidth = this->getWidth() / 5;
		this->childHeight = this->getHeight();
		this->maxScroll = static_cast<int>(this->childs.size()
										   * (this->childMarginLeft
											  + this->childWidth))
						  - this->getWidth();
	} else if (this->scroll == VERTICAL) {
		this->childWidth = this->getWidth();
		this->childHeight = this->getHeight() / 5;
		this->maxScroll = static_cast<int>(this->childs.size()
										   * (this->childMarginTop
											  + this->childHeight))
						  - this->getHeight();
	}
}
