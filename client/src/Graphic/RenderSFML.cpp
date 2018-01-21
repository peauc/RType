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
	this->_eventMap.insert(std::make_pair(sf::Keyboard::Up,
					      IRender::EventAction::UP));
	this->_eventMap.insert(std::make_pair(sf::Keyboard::Down,
					      EventAction::DOWN));
	this->_eventMap.insert(std::make_pair(sf::Keyboard::Left,
					      EventAction::LEFT));
	this->_eventMap.insert(std::make_pair(sf::Keyboard::Right,
					      EventAction::RIGHT));
	this->_eventMap.insert(std::make_pair(sf::Keyboard::Space,
					      EventAction::SPACE));
	this->_eventMap.insert(std::make_pair(sf::Mouse::Left,
					      EventAction::MOUSE1));
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
}

std::unique_ptr<ISprite> RenderSFML::createSprite(const std::string &fileName,
						  uint32_t sizeTileX,
						  uint32_t sizeTileY)
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

void	RenderSFML::draw(const IText *text) noexcept
{
	if (this->_window && text) {
		this->_window->draw(		//TODO Is there another way ?
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
		} else if (event.type == sf::Event::KeyPressed ||
			   event.type == sf::Event::MouseButtonPressed) {
			this->addEventToQueue(eventQueue, event.key.code);
		}
	}
	return (eventQueue);
}


void	RenderSFML::addEventToQueue(std::queue<IRender::EventAction>
				      &eventQueue, int key) noexcept
{
	auto it = this->_eventMap.find(key);
	if (it != this->_eventMap.end()) {
		eventQueue.push(it->second);
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
				std::cout << e.what() << std::endl;
			}
		}
		this->_textureMap.insert(std::make_pair(it.first,
							sfmlVectorTexture));
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
