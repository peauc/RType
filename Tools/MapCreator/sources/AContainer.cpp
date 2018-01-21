/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "AContainer.hpp"

AContainer::AContainer(AItem *parent) : AItem(parent) {
	this->childMarginTop = 0;
	this->childMarginBot = 0;
	this->childMarginLeft = 0;
	this->childMarginRight = 0;
}

AContainer::AContainer(const AContainer &obj) {
	this->childs = obj.childs;
}

AContainer &AContainer::operator=(const AContainer &obj) {
	if (&obj != this) {
		this->childs = obj.childs;
	}
	return (*this);
}

void AContainer::addChild(AItem *child) {
	this->childs.emplace_back(std::shared_ptr<AItem>(child));
}

void AContainer::lendBackgroundTexture(sf::Texture &texture) {
	this->background.setTexture(&texture, true);
}

const std::vector<std::shared_ptr<AItem>> &AContainer::getChilds() const {
	return (this->childs);
}
