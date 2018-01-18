/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "WindowManager.hpp"

WindowManager::WindowManager() {
	this->window.create(sf::VideoMode(1280,960,32),"MapCreator");
}

void WindowManager::start() {
	while (this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event)) {

		}
	}
}

void WindowManager::onClosed(const sf::Event &event) {

}

void WindowManager::onResized(const sf::Event &event) {

}

void WindowManager::onLostFocus(const sf::Event &event) {

}

void WindowManager::onGainedFocus(const sf::Event &event) {

}

void WindowManager::onKeyPressed(const sf::Event &event) {

}

void WindowManager::onKeyReleased(const sf::Event &event) {

}

void WindowManager::onMouseMoved(const sf::Event &event) {

}

void WindowManager::onMouseEntered(const sf::Event &event) {

}

void WindowManager::onMouseLeft(const sf::Event &event) {

}
