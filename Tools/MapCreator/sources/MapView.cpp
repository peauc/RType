/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "DuplicableItem.hpp"
#include "MapView.hpp"

MapView::MapView(Scroll scroll, AItem *parent)
		: AContainer(parent), spriteBackground(this) {
	this->scroll = scroll;
	this->maxScroll = 0;
	this->scrollSpeed = 30;
	this->scrollValue = 0;
	this->childMarginTop = 0;
	this->childMarginBot = 0;
	this->childMarginLeft = 0;
	this->childMarginRight = 0;
	this->background.setFillColor(sf::Color::White);
	this->associateEvents();
}

void MapView::displayOnWindow(sf::RenderWindow &window) {
	unsigned int	repeat = 0;

	window.draw(this->background);
	while (repeat < 1 || -this->scrollValue > this->getWidth() * (repeat - 1)) {
		this->spriteBackground.setX(this->getX() + this->scrollValue + repeat * this->getWidth());
		this->spriteBackground.refresh();
		this->spriteBackground.displayOnWindow(window);
		++repeat;
	}
	for (auto &child : this->childs)
		child->displayOnWindow(window);
}

void MapView::associateEvents() {
	this->actionsEvent[sf::Event::MouseWheelScrolled] =
			static_cast<AItem::Callback>(&MapView::onMouseWheelScrolled);
}

void MapView::receiveEvent(const sf::Event &event) {
	if (this->actionsEvent[event.type])
		(this->*(this->actionsEvent[event.type]))(event);
	for (auto &child : this->childs)
		child->receiveEvent(event);
}

void MapView::refresh() {
	this->spriteBackground.setX(this->getX() + this->scrollValue);
	this->spriteBackground.refresh();
	for (auto &child : this->childs) {
		auto	*upChild = dynamic_cast<DuplicableItem*>(child.get());

		upChild->setX(upChild->getXOnDuplicate() + this->scrollValue);
		child->refresh();
	}
}

void MapView::addChild(AItem *child) {
	dynamic_cast<DuplicableItem*>(child)
			->setXOnDuplicate(this->getX() - this->scrollValue);
	dynamic_cast<DuplicableItem*>(child)
			->setScrollOnDuplicate(this->scrollValue);
	child->setX(this->getX());
	child->setY(this->getY());
	child->setParent(this);
	AContainer::addChild(child);
	this->refresh();
}

void MapView::setModel(AListModel *model) {
	this->model.reset(model);
	this->model->loadDataModel();
}

void MapView::onMouseWheelScrolled(const sf::Event &event) {
	int		newScrollValue;

	if (this->inBounds(event.mouseWheelScroll.x, event.mouseWheelScroll.y)) {
		newScrollValue = static_cast<int>(this->scrollValue
										  + event.mouseWheelScroll.delta
											* this->scrollSpeed);
		if (newScrollValue < 0)
			this->scrollValue = newScrollValue;
		else
			this->scrollValue = 0;
		this->refresh();
	}
}

void MapView::lendBackgroundTexture(sf::Texture &texture) {
	this->spriteBackground.setTexture(texture);
}
