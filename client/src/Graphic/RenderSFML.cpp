/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <iostream>
#include <queue>
#include "Graphic/TextSFML.hpp"
#include "Graphic/SpriteSFML.hpp"
#include "Graphic/RenderSFML.hpp"

RenderSFML::RenderSFML()
 : _window(nullptr), _width(0), _height(0)
{
	this->initEventMap();
}

RenderSFML::RenderSFML(unsigned int width, unsigned int height,
                       const std::string &windowName)
 : _window(nullptr)
{
	this->initEventMap();
	this->openWindow(width, height, windowName);
}

void	RenderSFML::initEventMap()
{
	this->_eventMap.insert(std::make_pair(
		sf::Keyboard::Up, std::make_pair(EventAction::UP, false)));
	this->_eventMap.insert(std::make_pair(
		sf::Keyboard::Down, std::make_pair(EventAction::DOWN, false)));
	this->_eventMap.insert(std::make_pair(
		sf::Keyboard::Left, std::make_pair(EventAction::LEFT, false)));
	this->_eventMap.insert(std::make_pair(
		sf::Keyboard::Right,
		std::make_pair(EventAction::RIGHT, false)));
	this->_eventMap.insert(std::make_pair(
		sf::Keyboard::Space,
		std::make_pair(EventAction::SPACE, false)));
	this->_eventMap.insert(std::make_pair(
		sf::Mouse::Left,
		std::make_pair(EventAction::MOUSE1, false)));
}

void	RenderSFML::openWindow(unsigned int width, unsigned int height,
                               const std::string &windowName)
{
	this->_width = width;
	this->_height = height;
	if (this->_window != nullptr) {
		this->closeWindow();
	}
	this->_window = std::make_unique<sf::RenderWindow>(
		sf::VideoMode(width, height, RenderSFML::BPP), windowName);
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
	if (this->_musicLoaded) {
		this->_music.stop();
	}
}

std::unique_ptr<ISprite> RenderSFML::createSprite(const std::string &fileName,
						  uint32_t sizeTileX,
						  uint32_t sizeTileY)
{
	return (std::make_unique<SpriteSFML>(fileName, sizeTileX, sizeTileY));
}

void	RenderSFML::draw(const ISprite *sprite) noexcept
{
	if (this->_window && sprite && sprite->isDisplay()) {
		this->_window->draw(
			dynamic_cast<const SpriteSFML*>(sprite)->getSprite());
	}
}

void	RenderSFML::draw(const IText *text) noexcept
{
	if (this->_window && text) {
		this->_window->draw(
			dynamic_cast<const TextSFML*>(text)->getSText());
	}
}

std::queue<IRender::EventAction> RenderSFML::pollEvents() noexcept
{
	sf::Event				event{};
	std::queue<IRender::EventAction>	eventQueue;
	
	while (this->_window && this->_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed ||
		    (event.type == sf::Event::KeyPressed &&
		     event.key.code == sf::Keyboard::Escape)) {
			this->_window->close();
			eventQueue.push(IRender::EventAction::QUIT);
		} else if (event.type == sf::Event::KeyPressed ||
			   event.type == sf::Event::MouseButtonPressed) {
			this->setKeyPressedOrReleased((int)event.key.code,
						      true);
		} else if (event.type == sf::Event::KeyReleased ||
			event.type == sf::Event::MouseButtonReleased) {
			this->setKeyPressedOrReleased((int)event.key.code,
						      false);
		}
	}
	this->createEventQueue(eventQueue);
	return (eventQueue);
}

void RenderSFML::setKeyPressedOrReleased(int key, bool pressed)
{
	auto it = this->_eventMap.find(key);
	if (it != this->_eventMap.end()) {
		it->second.second = pressed;
	}
}

void RenderSFML::createEventQueue(std::queue<IRender::EventAction> &eventQueue)
{
	for (auto it : this->_eventMap) {
		if (it.second.second) {
			eventQueue.push(it.second.first);
		}
	}
}

void	RenderSFML::loadAnimations(std::unordered_map<uint32_t,
	std::vector<Texture>> textureMap)
{
	for (auto &it : textureMap) {
		auto &vectorTexture = it.second;
		std::vector<sf::Texture> sfmlVectorTexture;
		for (auto &texture : vectorTexture) {
			try {
				sfmlVectorTexture.push_back(
					this->loadTexture(texture));
			} catch (const std::runtime_error &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		this->_textureMap.insert(std::make_pair(it.first,
							sfmlVectorTexture));
	}
}

void RenderSFML::playMusic(const std::string &filePath)
{
	if (!this->_music.openFromFile(filePath)) {
		std::cerr << "Cannot open file : " << filePath << std::endl;
	} else {
		this->_musicLoaded = true;
		this->_music.play();
	}
}

sf::Texture		RenderSFML::loadTexture(const Texture &structTexture)
{
	sf::Texture	texture;
	
	if (!texture.loadFromFile(structTexture.filePath,
				  sf::IntRect(structTexture.left,
					      structTexture.top,
					      structTexture.width,
					      structTexture.height))) {
		throw std::runtime_error("Cannot open file : "
					 + structTexture.filePath);
	}
	return (texture);
}

void	RenderSFML::setAnimationToSprite(ISprite *sprite,
					     uint32_t idAnimation,
					     bool repeat) noexcept
{
	auto spriteSFML = dynamic_cast<SpriteSFML*>(sprite);
	auto it = this->_textureMap.find(idAnimation);
	if (it != this->_textureMap.end()) {
		spriteSFML->setAnimationId(idAnimation);
		spriteSFML->setAnimationVector(it->second, repeat);
	}
}

bool	RenderSFML::isSpriteClicked(const ISprite *sprite,
				 const EventAction &event) noexcept
{
	sf::Vector2i mPos = sf::Mouse::getPosition(*this->_window);
	const auto spriteSFML = dynamic_cast<const SpriteSFML*>(sprite);
	sf::FloatRect fr = spriteSFML->getSprite().getGlobalBounds();

	return (event == EventAction::MOUSE1 && fr.contains(mPos.x, mPos.y));
}

uint32_t RenderSFML::getWidth() const noexcept
{
	return (this->_width);
}

uint32_t RenderSFML::getHeight() const noexcept
{
	return (this->_height);
}
