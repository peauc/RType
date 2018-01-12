/*
** EPITECH PROJECT , 2020
** SFMLDemo
** File description :
** No description
*/

#ifndef SFMLDEMO_EXTRACTOR_HPP
#define SFMLDEMO_EXTRACTOR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Extractor {

public:

	Extractor() = default;
	~Extractor() = default;
	Extractor(const Extractor&) = delete;
	Extractor   &operator=(const Extractor&) = delete;

	void    extractSprites(const std::string &file);

	class Sprite
	{
	public:

		Sprite();
		~Sprite() = default;
		Sprite(const Sprite &obj);
		Sprite  &operator=(const Sprite &obj);

		void    setMinX(unsigned int minX);
		void    setMinY(unsigned int minY);
		void    setMaxX(unsigned int maxX);
		void    setMaxY(unsigned int maxY);
		void    setInitialized(bool state);

		unsigned int    getMinX() const;
		unsigned int    getMinY() const;
		unsigned int    getMaxX() const;
		unsigned int    getMaxY() const;
		unsigned int    getWidth() const;
		unsigned int    getHeight() const;

	private:

		unsigned int    minX;
		unsigned int    minY;
		unsigned int    maxX;
		unsigned int    maxY;
		bool            initialized;
	};

	const sf::Image             &getImage() const;
	const std::vector<Sprite>   &getSprites() const;

private:

	void        createPixels(unsigned int x, unsigned int y);
	void        browsePixels();
	void        tryCreateSprite(unsigned int x, unsigned int y);
	void        createSprite(Sprite &sprite, unsigned int x, unsigned int y);

	std::vector<Sprite>             sprites;
	sf::Image                       image;
	std::vector<std::vector<bool>>  pixels;

};


#endif //SFMLDEMO_EXTRACTOR_HPP
