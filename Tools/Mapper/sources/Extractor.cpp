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
	this->sortSprites();
	this->spritesEqualize = this->sprites;
	this->equalizeTileSprites();
}

void Extractor::createPixels(unsigned int x, unsigned int y) {
	this->pixels.reset(new PixelsArray(x, y, false));
}

void Extractor::browsePixels() {
	for (unsigned int y = 0; y < this->pixels->getHeight(); ++y)
	{
		for (unsigned int x = 0; x < this->pixels->getWidth(); ++x)
		{
			this->tryCreateSprite(x, y);
		}
	}
}

void Extractor::tryCreateSprite(unsigned int x, unsigned int y) {
	if (!this->isEmptyPixel(this->image.getPixel(x, y))
	    && !this->pixels->at(x, y))
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
	if (!this->pixels->outOfRange(x, y)
	    && !this->isEmptyPixel(this->image.getPixel(x, y))
	    && !this->pixels->at(x, y))
	{
		sprite.setMinX(x);
		sprite.setMinY(y);
		sprite.setMaxX(x);
		sprite.setMaxY(y);
		this->pixels->at(x, y) = true;
		this->addTails(x, y);
	}
}

const sf::Image &Extractor::getImage() const {
	return (this->image);
}

const std::vector<Sprite> &Extractor::getSprites() const {
	return (this->sprites);
}

const std::vector<Sprite> &Extractor::getSpritesEqualize() const {
	return (this->spritesEqualize);
}

bool Extractor::isEmptyPixel(const sf::Color &pixelColor) const {
	return (pixelColor.a == 0);
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

void Extractor::equalizeTileSprites() {
	TileEqualizer	tileEqualizer(this->spritesEqualize);

	tileEqualizer.equalize();
}
