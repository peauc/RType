/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "ASpriteInList.hpp"

ASpriteInList::ASpriteInList(AItem *parent) : ASpriteItem(parent) {

}

ASpriteInList::ASpriteInList(const ASpriteInList &obj) :  ASpriteItem(obj) {

}

void ASpriteInList::refresh() {
	this->displayOnlyInParentBounds();
	ASpriteItem::refresh();
}

void ASpriteInList::displayOnlyInParentBounds() {
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
