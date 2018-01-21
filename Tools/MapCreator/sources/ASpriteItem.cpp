/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "ASpriteItem.hpp"

ASpriteItem::ASpriteItem(AItem *parent) : AItem(parent) {

}

ASpriteItem::ASpriteItem(const ASpriteItem &obj) : AItem(obj) {
	this->texture = obj.texture;
	this->icon = obj.icon;
}

void ASpriteItem::refresh() {

}

int ASpriteItem::getXTexture() {
	int		x = 0;

	if (this->needMoveXTexture()) {
		x += this->getXOutSize() / this->getRealScaleX();
		return (x > this->texture.getSize().x ? this->texture.getSize().x : x);
	} else
		return (0);
}

int ASpriteItem::getYTexture() {
	int		y = 0;

	if (this->needMoveYTexture()) {
		y += this->getYOutSize() / this->getRealScaleY();
		return (y > this->texture.getSize().y ? this->texture.getSize().y : y);
	}
	return (0);
}

int ASpriteItem::getWidthTexture() {
	int		width = this->texture.getSize().x;

	if (this->needReduceWidthTexture()) {
		width -= this->getXOutSize() / this->getRealScaleX();
		return (width < 0 ? 0 : width);
	} else
		return (this->texture.getSize().x);
}

int ASpriteItem::getHeightTexture() {
	int 	height = this->texture.getSize().y;

	if (this->needReduceHeightTexture()) {
		height -= this->getYOutSize() / this->getRealScaleY();
		return (height < 0 ? 0 : height);
	} else
		return (this->texture.getSize().y);
}

float ASpriteItem::getScaleX() {
	return (static_cast<float>((this->getWidth() - this->getXOutSize())) /
			 static_cast<float>(this->getWidthTexture()
								- this->getXTexture()));
}

float ASpriteItem::getScaleY() {
	return (static_cast<float>((this->getHeight() - this->getYOutSize())) /
			static_cast<float>(this->getHeightTexture()
							   - this->getYTexture()));
}

int ASpriteItem::getXOutSize() {
	if (this->needMoveXTexture())
		return (-(this->getX() - this->parent->getX()));
	else if (this->needReduceWidthTexture())
		return (this->getX() + this->getRealWidth())
			   - (this->parent->getX() + this->parent->getWidth());
	return (0);
}

int ASpriteItem::getYOutSize() {
	if (this->needMoveYTexture())
		return (-(this->getY() - this->parent->getY()));
	else if (this->needReduceHeightTexture())
		return ((this->getY() + this->getRealHeight())
			   - (this->parent->getY() + this->parent->getHeight()));
	return (0);
}

int ASpriteItem::getRealWidth() {
	return (this->getWidth());
}

int ASpriteItem::getRealHeight() {
	return (this->getHeight());
}

float ASpriteItem::getRealScaleX() {
	return (static_cast<float>(this->getWidth())
			/ static_cast<float>(this->texture.getSize().x));
}

float ASpriteItem::getRealScaleY() {
	return (static_cast<float>(this->getHeight())
			/ static_cast<float>(this->texture.getSize().y));
}

bool ASpriteItem::needMoveXTexture() {
	return (this->getX() < this->parent->getX());
}

bool ASpriteItem::needReduceWidthTexture() {
	return (this->getX() + this->getRealWidth()
			> this->parent->getX() + this->parent->getWidth());
}

bool ASpriteItem::needMoveYTexture() {
	return (this->getY() < this->parent->getY());
}

bool ASpriteItem::needReduceHeightTexture() {
	return (this->getY() + this->getRealHeight()
			> this->parent->getY() + this->parent->getHeight());
}
