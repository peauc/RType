/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "GridLayout.hpp"

GridLayout::GridLayout(AItem *parent) : AContainer(parent) {
	this->background.setFillColor(sf::Color::Black);
	this->associateEvents();
}

void GridLayout::displayOnWindow(sf::RenderWindow &window) {
	window.draw(this->background);
	for (auto &child : this->childs)
		child->displayOnWindow(window);
}

void GridLayout::associateEvents() {

}

void GridLayout::receiveEvent(const sf::Event &event) {
	if (this->actionsEvent[event.type])
		(this->*(this->actionsEvent[event.type]))(event);
	for (auto &child : this->childs)
		child->receiveEvent(event);
}

void GridLayout::refresh() {
	for (auto &child : this->childs)
		child->refresh();
}

void GridLayout::addChild(AItem *child, const Range &range) {
	child->setX(this->getPValue(range.pSWidth, this->getWidth()));
	child->setY(this->getPValue(range.pSHeight, this->getHeight()));
	child->setWidth(this->getPValue(range.pEWidth - range.pSWidth,
									this->getWidth()));
	child->setHeight(this->getPValue(range.pEHeight - range.pSHeight,
									 this->getHeight()));
	child->setParent(this);
	AContainer::addChild(child);
	this->refresh();
}

int GridLayout::getPValue(int p, int value) const {
	int	pValue;

	pValue = static_cast<int>(value / 100.0 * p);
	return (pValue);
}
