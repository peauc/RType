/*
** EPITECH PROJECT , 2020
** SFMLDemo
** File description :
** No description
*/

#include <iostream>
#include <fstream>
#include "Displayer.hpp"

void Displayer::displaySprites(const Extractor &extractor) {
	if (extractor.getSprites().size() == 0)
		return ;
	this->initDisplayer(extractor);
	this->createEvents();
	while(this->window.isOpen())
	{
		sf::Event event;
		while (this->window.pollEvent(event))
		{
			this->checkEvents(event);
			this->drawSprite();
		}
	}
}

void Displayer::initDisplayer(const Extractor &extractor) {
	this->window.create(sf::VideoMode(640,480,32),"Displayer");
	this->needToSave = false;
	this->scale = 1;
	this->sprites = extractor.getSprites();
	this->spriteIndex = 0;
	this->texture.loadFromImage(extractor.getImage());
	this->sprite.setTexture(this->texture, true);
	this->resolveTextureRect();
	this->sprite.setTextureRect(this->textureRect);
}

void Displayer::checkEvents(const sf::Event &event) {
	if (event.type == sf::Event::Closed
	    || (event.type == sf::Event::KeyPressed
	        && event.key.code == sf::Keyboard::Escape)
	    || (event.type == sf::Event::KeyPressed
	        && event.key.code == sf::Keyboard::Return))
		this->window.close();
	else if (event.type == sf::Event::KeyPressed)
		this->doEvent(event.key.code);
	this->needToSave = (event.type == sf::Event::KeyPressed
	                    && event.key.code == sf::Keyboard::Return);
}

void Displayer::drawSprite() {
	this->sprite.setPosition(this->window.getSize().x / 2
	                         - this->sprite.getTextureRect().width / 2
	                           * this->sprite.getScale().x,
	                         this->window.getSize().y / 2
	                         - this->sprite.getTextureRect().height / 2
	                           * this->sprite.getScale().y);
	this->window.clear(sf::Color::Black);
	this->window.draw(this->sprite);
	this->window.display();
}

void Displayer::resolveTextureRect() {
	this->textureRect.left = this->sprites.at(this->spriteIndex).getMinX();
	this->textureRect.top = this->sprites.at(this->spriteIndex).getMinY();
	this->textureRect.width = this->sprites.at(this->spriteIndex).getWidth();
	this->textureRect.height = this->sprites.at(this->spriteIndex).getHeight();
}

void Displayer::createEvents() {
	Displayer::Callback   func;

	func = std::bind(&Displayer::onNextSprite, this);
	this->actions.insert(std::make_pair(sf::Keyboard::Right, func));
	func = std::bind(&Displayer::onPrevSprite, this);
	this->actions.insert(std::make_pair(sf::Keyboard::Left, func));
	func = std::bind(&Displayer::onRemoveSprite, this);
	this->actions.insert(std::make_pair(sf::Keyboard::Delete, func));
	func = std::bind(&Displayer::onZoomIn, this);
	this->actions.insert(std::make_pair(sf::Keyboard::Up, func));
	func = std::bind(&Displayer::onZoomOut, this);
	this->actions.insert(std::make_pair(sf::Keyboard::Down, func));
}

void Displayer::doEvent(sf::Keyboard::Key key) {
	auto action = this->actions.find(key);

	if (action != this->actions.end())
	{
		action->second();
	}
}

void Displayer::onNextSprite() {
	if (this->spriteIndex < this->sprites.size() - 1)
		this->spriteIndex++;
	this->resolveTextureRect();
	this->sprite.setTextureRect(this->textureRect);
}

void Displayer::onPrevSprite() {
	if (this->spriteIndex > 0)
		this->spriteIndex--;
	this->resolveTextureRect();
	this->sprite.setTextureRect(this->textureRect);
}

void Displayer::onRemoveSprite() {
	if (this->spriteIndex < this->sprites.size())
	{
		this->sprites.erase(std::next(this->sprites.begin(), this->spriteIndex));
		if (this->sprites.empty())
			this->window.close();
		else {
			if (this->spriteIndex == this->sprites.size())
				this->spriteIndex = 0;
			this->resolveTextureRect();
			this->sprite.setTextureRect(this->textureRect);
		}
	}
}

void Displayer::onZoomIn() {
	this->scale *= 2;
	this->sprite.setScale(this->scale, this->scale);
}

void Displayer::onZoomOut() {
	this->scale /= 2;
	this->sprite.setScale(this->scale, this->scale);
}

void Displayer::saveSprites(const std::string &baseName,
                            const std::string &format,
                            const std::string &dest) const {
	std::string     filePath;
	unsigned int    index = 0;

	for (auto &sprite : this->sprites)
	{
		filePath = dest + baseName;
		filePath += std::to_string(index) + ".sprite";
		std::cout << "filePath : " << filePath << std::endl;
		std::ofstream    file(filePath, std::ios::out);

		if (file)
		{
			file << (format == "json" ? this->jsonFormat(sprite)
			                          : this->defaultFormat(sprite));
			file.close();
		}
		else
			std::cerr << "Can't open file : " << filePath << std::endl;
		++index;
	}
}

std::string Displayer::defaultFormat(const Extractor::Sprite &sprite) const {
	std::string format;

	format = std::to_string(sprite.getMinX()) + " : ";
	format += std::to_string(sprite.getMinY()) + " : ";
	format += std::to_string(sprite.getWidth()) + " : ";
	format += std::to_string(sprite.getHeight());
	return (format);
}

std::string Displayer::jsonFormat(const Extractor::Sprite &sprite) const {
	std::string format;

	format = "{";
	format += "\n\t x : " + std::to_string(sprite.getMinX());
	format += "\n\t y : " + std::to_string(sprite.getMinY());
	format += "\n\t width : " + std::to_string(sprite.getWidth());
	format += "\n\t height : " + std::to_string(sprite.getHeight());
	format += "\n}";
	return (format);
}

bool Displayer::getNeedToSave() const {
	return (this->needToSave);
}


