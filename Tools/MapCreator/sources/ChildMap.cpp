/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "DuplicableItem.hpp"
#include "ChildMap.hpp"

ChildMap::ChildMap(AItem *parent)
		: ASpriteBackground(parent) {
	this->pathItem = "";
	this->resizing = false;
	this->scrollValue = 0;
	this->selected = false;
	this->background.setFillColor(sf::Color(224, 224, 224, 100));
	this->associateEvents();
}

ChildMap::ChildMap(const ChildMap &obj)
		: ASpriteBackground(obj) {
	this->selected = false;
	this->pathItem = obj.pathItem;
}

void ChildMap::displayOnWindow(sf::RenderWindow &window) {
	window.draw(this->background);
	window.draw(this->icon);
}

void ChildMap::associateEvents() {
	this->actionsEvent[sf::Event::MouseButtonPressed] =
			static_cast<AItem::Callback>
			(&ChildMap::onMouseButtonPressed);
	this->actionsEvent[sf::Event::MouseButtonReleased] =
			static_cast<AItem::Callback>
			(&ChildMap::onMouseButtonReleased);
	this->actionsEvent[sf::Event::MouseMoved] =
			static_cast<AItem::Callback>
			(&ChildMap::onMouseMoved);
}

void ChildMap::receiveEvent(const sf::Event &event) {
	if (this->actionsEvent[event.type])
		(this->*(this->actionsEvent[event.type]))(event);
}

void ChildMap::refresh() {
	this->displayOnlyInParentBounds();
}

void ChildMap::displayOnlyInParentBounds() {
	if (!parent)
		return ;
	sf::Rect<int>	rect;

	rect.left = this->getXTexture();
	rect.top = this->getYTexture();
	rect.width = this->getWidthTexture() - rect.left;
	rect.height = this->getHeightTexture() - rect.top;
	this->icon.setTextureRect(rect);
	this->icon.setScale(this->getScaleX(), this->getScaleY());
	if (this->needMoveXTexture() || this->needMoveYTexture())
		this->icon.setPosition(this->getX() + this->getXOutSize(),
							   this->getY() + this->getYOutSize());
	else
		this->icon.setPosition(this->getX(), this->getY());
}

void ChildMap::onMouseButtonPressed(const sf::Event &event) {
	if (this->inBounds(event.mouseButton.x, event.mouseButton.y)) {
		if (event.mouseButton.button == sf::Mouse::Button::Left)
			this->selected = true;
		else if (this->pathItem.empty()
				 && event.mouseButton.button == sf::Mouse::Button::Right)
			this->resizing = true;
	}
}

void ChildMap::onMouseButtonReleased(const sf::Event &event) {
	if (event.mouseButton.button == sf::Mouse::Button::Left)
		this->selected = false;
	else if (event.mouseButton.button == sf::Mouse::Button::Right)
		this->resizing = false;
}

void ChildMap::onMouseMoved(const sf::Event &event) {
	if (this->selected) {
		this->setX((event.mouseMove.x - this->getWidth() / 2));
		this->setY(event.mouseMove.y - this->getHeight() / 2);
		this->refresh();
	}
	if (this->resizing) {
		int		width = (event.mouseMove.x - this->getX());
		int		height = (event.mouseMove.y - this->getY());

		if (width > 0 && height > 0) {
			this->setWidth(width);
			this->setHeight(height);
		}
	}
}

ChildMap::ChildMap(const DuplicableItem &obj)
		: ASpriteBackground(obj) {
	this->selected = false;
	this->pathItem = obj.getPathItem();
}

void ChildMap::setScrollValue(int scrollValue) {
	this->scrollValue = scrollValue;
}

int ChildMap::getScrollValue() const {
	return (this->scrollValue);
}

const std::string &ChildMap::getPathItem() const {
	return (this->pathItem);
}

bool ChildMap::isResizing() {
	return (this->resizing);
}

void ChildMap::setResizing(bool state) {
	this->resizing = state;
}
