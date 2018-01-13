/*
** EPITECH PROJECT , 2020
** SFMLDemo
** File description :
** No description
*/

#ifndef SFMLDEMO_DISPLAYER_HPP
#define SFMLDEMO_DISPLAYER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <functional>
#include "Extractor.hpp"

class Displayer {

public:

	Displayer() = default;
	~Displayer() = default;
	Displayer(const Displayer&) = delete;
	Displayer   &operator=(const Displayer&) = delete;

	void    displaySprites(const Extractor &extractor);
	bool    getNeedToSave() const;
	void    saveSprites(const std::string &baseName,
	                    const std::string &format,
	                    const std::string &dest) const;

private:

	void    initDisplayer(const Extractor &extractor);
	void    checkEvents(const sf::Event &event);
	void    drawSprite();
	void    resolveTextureRect();
	void    createEvents();
	void    doEvent(sf::Keyboard::Key key);
	void    onNextSprite();
	void    onPrevSprite();
	void    onRemoveSprite();
	void    onZoomIn();
	void    onZoomOut();

	std::string     defaultFormat(const Extractor::Sprite &sprite) const;
	std::string     jsonFormat(const Extractor::Sprite &sprite) const;

	sf::RenderWindow                    window;
	std::vector<Extractor::Sprite>      sprites;
	sf::Sprite                          sprite;
	sf::Texture                         texture;
	sf::Rect<int>                       textureRect;
	unsigned int                        spriteIndex;
	float                               scale;
	bool                                needToSave;

	using Callback = std::function<void(void)>;

	std::map<sf::Keyboard::Key, Displayer::Callback>    actions;

};


#endif //SFMLDEMO_DISPLAYER_HPP
