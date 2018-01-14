/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#ifndef SFMLDEMO_EXTRACTOR_HPP
#define SFMLDEMO_EXTRACTOR_HPP

#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>
#include "Sprite.hpp"


class Extractor {

public:

	Extractor() = default;
	~Extractor() = default;
	Extractor(const Extractor&) = delete;
	Extractor   &operator=(const Extractor&) = delete;

	void    extractSprites(const std::string &file);

	const sf::Image             &getImage() const;
	const std::vector<Sprite>   &getSprites() const;

private:

	using PixelsTab = std::vector<std::vector<bool>>;

	void        createPixels(unsigned int x, unsigned int y);
	void        browsePixels();
	void        tryCreateSprite(unsigned int x, unsigned int y);
	void        createSprite(Sprite &sprite, unsigned int x, unsigned int y);
	bool        isEmptyPixel(const sf::Color &pixelColor) const;
	bool        pixelIsOutOfRange(unsigned int x, unsigned int y) const;
	void        addTails(unsigned int x, unsigned int y);
	void        sortSprites();

	std::vector<Sprite>                     sprites;
	sf::Image                               image;
	PixelsTab                               pixels;
	std::queue<sf::Vector2<unsigned int>>   tails;

};


#endif //SFMLDEMO_EXTRACTOR_HPP
