/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "DuplicableItem.hpp"
#include "ASpriteBackground.hpp"

ASpriteBackground::ASpriteBackground(AItem *parent) : ASpriteItem(parent) {

}

ASpriteBackground::ASpriteBackground(const ASpriteBackground &obj)
		: ASpriteItem(obj) {

}

ASpriteBackground::ASpriteBackground(const DuplicableItem &obj)
		: ASpriteItem(obj){

}

void ASpriteBackground::refresh() {
	this->displayOnlyInParentBounds();
	ASpriteItem::refresh();
}

void ASpriteBackground::displayOnlyInParentBounds() {
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
