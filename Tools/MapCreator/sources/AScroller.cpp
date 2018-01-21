/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "AScroller.hpp"

AScroller::AScroller() {
	this->scroll = HORIZONTAL;
	this->scrollSpeed = 1.0;
}

AScroller::AScroller(const AScroller &obj) {
	this->scroll = obj.scroll;
	this->scrollSpeed = obj.scrollSpeed;
	this->scrollValue = obj.scrollValue;
	this->maxScroll = obj.maxScroll;
}

AScroller &AScroller::operator=(const AScroller &obj) {
	if (&obj != this) {
		this->scroll = obj.scroll;
		this->scrollSpeed = obj.scrollSpeed;
		this->scrollValue = obj.scrollValue;
		this->maxScroll = obj.maxScroll;
	}
	return (*this);
}
