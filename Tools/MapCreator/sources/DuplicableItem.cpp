/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include <boost/filesystem.hpp>
#include "ChildMap.hpp"
#include "DuplicableItem.hpp"

DuplicableItem::DuplicableItem(const std::string &iconPath,
							   AItem *parent, AContainer *employer)
		: ASpriteInList(parent) {
	auto	p = boost::filesystem::path(iconPath);

	this->texture.loadFromFile(iconPath);
	this->icon.setTexture(this->texture, true);
	this->employer = employer;
	this->pathItem = p.replace_extension(".so").string();
	this->associateEvents();
}

DuplicableItem::DuplicableItem(const DuplicableItem &obj)
		: ASpriteInList(obj) {
	this->employer = nullptr;
	this->pathItem = obj.pathItem;
}

void DuplicableItem::displayOnWindow(sf::RenderWindow &window) {
	window.draw(this->icon);
}

void DuplicableItem::associateEvents() {
	this->actionsEvent[sf::Event::MouseButtonPressed] =
			static_cast<AItem::Callback>
			(&DuplicableItem::onMouseButtonPressed);
	this->actionsEvent[sf::Event::MouseButtonReleased] =
			static_cast<AItem::Callback>
			(&DuplicableItem::onMouseButtonReleased);
	this->actionsEvent[sf::Event::MouseMoved] =
			static_cast<AItem::Callback>
			(&DuplicableItem::onMouseMoved);
}

void DuplicableItem::receiveEvent(const sf::Event &event) {
	if (this->actionsEvent[event.type])
		(this->*(this->actionsEvent[event.type]))(event);
}

void DuplicableItem::refresh() {
	ASpriteInList::refresh();
}

void DuplicableItem::onMouseButtonPressed(const sf::Event &event) {
	if (this->inBounds(event.mouseButton.x, event.mouseButton.y)) {
		if (this->employer)
			this->employer->addChild(new ChildMap(*this));
	}
}

void DuplicableItem::onMouseButtonReleased(const sf::Event &event) {

}

void DuplicableItem::onMouseMoved(const sf::Event &event) {

}

const std::string &DuplicableItem::getPathItem() const {
	return (this->pathItem);
}



