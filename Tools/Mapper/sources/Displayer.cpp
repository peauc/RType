/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include "Sprite.hpp"
#include "Displayer.hpp"

Displayer::Displayer(SpriteManager &spriteManager)
		: spriteManager(spriteManager) {
	this->fontLoaded = this->font.loadFromFile("fonts/arial.ttf");
	if (this->fontLoaded)
		this->mode.setFont(font);
	this->mode.setString("Mode : Sprite");
	this->mode.setCharacterSize(24);
	this->mode.setColor(sf::Color::Green);
	this->border.setOutlineThickness(2);
	this->border.setOutlineColor(sf::Color::Green);
	this->border.setFillColor(sf::Color::Transparent);
}

void Displayer::displaySprites() {
	if (!this->spriteManager.availableSprites())
		return ;
	this->initDisplayer();
	this->createEvents();
	while(this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event)) {
			this->checkEvents(event);
			this->drawSprite();
		}
	}
}

void Displayer::initDisplayer() {
	this->window.create(sf::VideoMode(640,480,32),"Mapper");
	this->scale = 1;
	this->spriteIndex = 0;
	this->texture.loadFromImage(this->spriteManager.getImage());
	this->sprite.setTexture(this->texture, true);
	this->resolveTextureRect();
	this->sprite.setTextureRect(this->textureRect);
}

void Displayer::checkEvents(const sf::Event &event) {
	if (event.type == sf::Event::Closed
	    || (event.type == sf::Event::KeyPressed
	        && event.key.code == sf::Keyboard::Escape))
		this->window.close();
	else if (event.type == sf::Event::KeyPressed)
		this->doEvent(event.key.code);
}

void Displayer::drawSprite() {
	this->resolveSizeRect();
	this->window.clear(sf::Color::Black);
	if (this->spriteManager.spriteIsSelected(this->spriteIndex))
		this->window.draw(this->border);
	this->window.draw(this->sprite);
	if (this->fontLoaded)
		this->window.draw(this->mode);
	this->window.display();
}

void Displayer::resolveTextureRect() {
	std::vector<Sprite> &sprites = this->spriteManager.getSprites();
	float               margin = 2;

	this->textureRect.left = sprites.at(this->spriteIndex).getMinX();
	this->textureRect.top = sprites.at(this->spriteIndex).getMinY();
	this->textureRect.width = sprites.at(this->spriteIndex).getWidth();
	this->textureRect.height = sprites.at(this->spriteIndex).getHeight();

	this->border.setSize(sf::Vector2f {this->textureRect.width + margin,
	                                   this->textureRect.height + margin});
}

void Displayer::resolveSizeRect() {
	this->sprite.setPosition(this->window.getSize().x / 2
	                         - this->sprite.getTextureRect().width / 2
	                           * this->sprite.getScale().x,
	                         this->window.getSize().y / 2
	                         - this->sprite.getTextureRect().height / 2
	                           * this->sprite.getScale().y);
	this->border.setPosition(this->window.getSize().x / 2
	                         - this->border.getSize().x / 2
	                           * this->border.getScale().x,
	                         this->window.getSize().y / 2
	                         - this->border.getSize().y / 2
	                           * this->border.getScale().y);
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
	func = std::bind(&Displayer::onSelect, this);
	this->actions.insert(std::make_pair(sf::Keyboard::Space, func));
	func = std::bind(&Displayer::onSelectAll, this);
	this->actions.insert(std::make_pair(sf::Keyboard::A, func));
	func = std::bind(&Displayer::onChangeMode, this);
	this->actions.insert(std::make_pair(sf::Keyboard::M, func));
	func = std::bind(&Displayer::onSave, this);
	this->actions.insert(std::make_pair(sf::Keyboard::Return, func));
}

void Displayer::doEvent(sf::Keyboard::Key key) {
	auto action = this->actions.find(key);

	if (action != this->actions.end())
	{
		action->second();
	}
}

void Displayer::onNextSprite() {
	if (this->spriteIndex < this->spriteManager.getSprites().size() - 1)
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
	this->spriteIndex = this->spriteManager.removeSprite(this->spriteIndex);
	if (this->spriteManager.availableSprites()) {
		this->resolveTextureRect();
		this->sprite.setTextureRect(this->textureRect);
	} else
		this->window.close();
}

void Displayer::onZoomIn() {
	this->scale *= 2;
	this->sprite.setScale(this->scale, this->scale);
	this->border.setScale(this->scale, this->scale);
}

void Displayer::onZoomOut() {
	this->scale /= 2;
	this->sprite.setScale(this->scale, this->scale);
	this->border.setScale(this->scale, this->scale);
}

void Displayer::onSelect() {
	bool    state = !this->spriteManager.spriteIsSelected(this->spriteIndex);

	this->spriteManager.setSpriteSelected(this->spriteIndex, state);
}

void Displayer::onChangeMode() {
	this->mode.setString((this->mode.getString() == "Mode : Sprite" ?
	                      "Mode : Animation" : "Mode : Sprite"));
}

void Displayer::onSelectAll() {
	unsigned long   size = this->spriteManager.getSprites().size();
	bool            state = !this->spriteManager.allSelected();

	for (unsigned int index = 0; index < size; ++index)
		this->spriteManager.setSpriteSelected(index, state);
}

void Displayer::onSave() {
	if (this->mode.getString() == "Mode : Sprite")
		this->spriteManager.saveSprites();
	else
		this->spriteManager.saveAnimation();
	this->spriteManager.resetSelected();
}
