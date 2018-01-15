/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#include "Sprite.hpp"
#include "Extractor.hpp"

void Extractor::extractSprites(const std::string &file) {
	if (!this->image.loadFromFile(file))
		return ;
	this->createPixels(this->image.getSize().x, this->image.getSize().y);
	this->browsePixels();
}

void Extractor::createPixels(unsigned int x, unsigned int y) {
	this->pixels = PixelsTab(y, std::vector<bool>(x, false));
}

void Extractor::browsePixels() {
	for (unsigned int y = 0; y < this->pixels.size(); ++y)
	{
		for (unsigned int x = 0; x < this->pixels.at(y).size(); ++x)
		{
			this->tryCreateSprite(x, y);
		}
	}
	this->sortSprites();
}

void Extractor::tryCreateSprite(unsigned int x, unsigned int y) {
	if (!this->isEmptyPixel(this->image.getPixel(x, y))
	    && !this->pixels.at(y).at(x))
	{
		Sprite  sprite;

		sprite.setMinX(x);
		sprite.setMinY(y);
		sprite.setMaxX(x);
		sprite.setMaxY(y);
		sprite.setInitialized(true);
		this->addTails(x, y);
		while (!this->tails.empty()) {
			this->createSprite(sprite, this->tails.front().x,
			                   this->tails.front().y);
			this->tails.pop();
		}
		if (sprite.getWidth() > 1 || sprite.getHeight() > 1)
			this->sprites.push_back(sprite);
	}
}

void Extractor::createSprite(Sprite &sprite,
                             unsigned int x, unsigned int y) {
	if (!this->pixelIsOutOfRange(x, y)
	    && !this->isEmptyPixel(this->image.getPixel(x, y))
	    && !this->pixels.at(y).at(x))
	{
		sprite.setMinX(x);
		sprite.setMinY(y);
		sprite.setMaxX(x);
		sprite.setMaxY(y);
		this->pixels.at(y).at(x) = true;
		this->addTails(x, y);
	}
}

const sf::Image &Extractor::getImage() const {
	return (this->image);
}

const std::vector<Sprite> &Extractor::getSprites() const {
	return (this->sprites);
}

bool Extractor::isEmptyPixel(const sf::Color &pixelColor) const {
	return (pixelColor.a == 0);
}

bool Extractor::pixelIsOutOfRange(unsigned int x, unsigned int y) const {
	return (!(y >= 0 && y < pixels.size()
	          && x >= 0 && x < pixels.at(y).size()));
}

void Extractor::addTails(unsigned int x, unsigned int y) {
	this->tails.push(sf::Vector2<unsigned int> {x - 1, y} );
	this->tails.push(sf::Vector2<unsigned int> {x + 1, y} );
	this->tails.push(sf::Vector2<unsigned int> {x, y - 1} );
	this->tails.push(sf::Vector2<unsigned int> {x, y + 1} );
	this->tails.push(sf::Vector2<unsigned int> {x - 1, y - 1} );
	this->tails.push(sf::Vector2<unsigned int> {x + 1, y + 1} );
	this->tails.push(sf::Vector2<unsigned int> {x - 1, y + 1} );
	this->tails.push(sf::Vector2<unsigned int> {x + 1, y - 1} );
}

void Extractor::sortSprites() {
	std::sort(this->sprites.begin(), this->sprites.end(),
	          [](const Sprite &one, const Sprite &two)
	          {
		          if (one.getMinY() + one.getHeight() < two.getMinY())
			          return (true);
		          else if (two.getMinY() + two.getHeight() < one.getMinY())
			          return (false);
		          return (one.getMinX() < two.getMinX());
	          } );
}

