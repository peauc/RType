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
#include "PixelsArray.hpp"
#include "Sprite.hpp"
#include "TileEqualizer.hpp"


class Extractor {

public:

	Extractor() = default;
	~Extractor() = default;
	Extractor(const Extractor&) = delete;
	Extractor   &operator=(const Extractor&) = delete;

	void    extractSprites(const std::string &file);

	const sf::Image             &getImage() const;
	const std::vector<Sprite>   &getSprites() const;
	const std::vector<Sprite>   &getSpritesEqualize() const;

private:

	void        createPixels(unsigned int x, unsigned int y);
	void        browsePixels();
	void        tryCreateSprite(unsigned int x, unsigned int y);
	void        createSprite(Sprite &sprite, unsigned int x, unsigned int y);
	bool        isEmptyPixel(const sf::Color &pixelColor) const;
	void        addTails(unsigned int x, unsigned int y);
	void        sortSprites();
	void		equalizeTileSprites();

	std::vector<Sprite>                     sprites;
	std::vector<Sprite>                     spritesEqualize;
	sf::Image                               image;
	std::unique_ptr<PixelsArray>			pixels;
	std::queue<sf::Vector2<unsigned int>>   tails;

};


#endif //SFMLDEMO_EXTRACTOR_HPP
