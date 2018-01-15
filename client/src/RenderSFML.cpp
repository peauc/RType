/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <iostream>
#include <queue>
#include "SpriteSFML.hpp"
#include "RenderSFML.hpp"

RenderSFML::RenderSFML(unsigned int width, unsigned int height,
                       const std::string &windowName) noexcept
{
	this->_eventMap.insert(std::make_pair(sf::Keyboard::Up,
					      EventAction::UP));
	this->_eventMap.insert(std::make_pair(sf::Keyboard::Down,
					      EventAction::DOWN));
	this->_eventMap.insert(std::make_pair(sf::Keyboard::Left,
					      EventAction::LEFT));
	this->_eventMap.insert(std::make_pair(sf::Keyboard::Right,
					      EventAction::RIGHT));
	this->_eventMap.insert(std::make_pair(sf::Keyboard::Space,
					      EventAction::ACTION));
	this->openWindow(width, height, windowName);
}

void	RenderSFML::openWindow(unsigned int width, unsigned int height,
                               const std::string &windowName) noexcept
{
	if (this->_window) {
		this->closeWindow();
	}
	this->_window = std::make_unique<sf::RenderWindow>(
		sf::VideoMode(width, height, RenderSFML::BPP),
		windowName);
}

bool	RenderSFML::isWindowOpen() noexcept
{
	if (this->_window) {
		return (this->_window->isOpen());
	}
	return (false);
}

void	RenderSFML::display() noexcept
{
	if (this->_window) {
		this->_window->display();
	}
}

void	RenderSFML::clear() noexcept
{
	if (this->_window) {
		this->_window->clear();
	}
}

void	RenderSFML::closeWindow() noexcept
{
	if (this->_window) {
		this->_window->close();
	}
}

std::unique_ptr<ISprite> RenderSFML::createSprite(const std::string &fileName,
						  uint32_t sizeTileX,
						  uint32_t sizeTileY) noexcept
{
	return (std::make_unique<SpriteSFML>(fileName, sizeTileX, sizeTileY));
}

void	RenderSFML::draw(const ISprite *sprite) noexcept
{
	if (this->_window && sprite) {
		this->_window->draw(		//TODO Is there another way ?
			dynamic_cast<const SpriteSFML*>(sprite)->getSprite());
	}
}

/**
 * Renvoi une queue d'events
 */
std::queue<IRender::EventAction>	RenderSFML::pollEvents() noexcept
{
	sf::Event				event;
	std::queue<IRender::EventAction>	eventQueue;
	
	while (this->_window && this->_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed ||
		    (event.type == sf::Event::KeyPressed &&
		     event.key.code == sf::Keyboard::Escape)) {
			this->_window->close();
		} else if (event.type == sf::Event::KeyPressed) {
			this->addEventToQueue(eventQueue, event.key.code);
		}
	}
	return (eventQueue);
}

void	RenderSFML::addEventToQueue(std::queue<IRender::EventAction>
				      &eventQueue, sf::Keyboard::Key key)
{
	auto it = this->_eventMap.find(key);
	if (it != this->_eventMap.end()) {
		eventQueue.push(it->second);
	}
}
