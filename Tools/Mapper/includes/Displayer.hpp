/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#ifndef SFMLDEMO_DISPLAYER_HPP
#define SFMLDEMO_DISPLAYER_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include <map>
#include "SpriteManager.hpp"
#include "Extractor.hpp"
#include "Sprite.hpp"

class Displayer {

public:

	Displayer(SpriteManager &spriteManager);
	~Displayer() = default;
	Displayer(const Displayer&) = delete;
	Displayer   &operator=(const Displayer&) = delete;

	void    displaySprites();

private:

	void    initDisplayer();
	void    checkEvents(const sf::Event &event);
	void    drawSprite();
	void    resolveTextureRect();
	void    resolveSizeRect();
	void    createEvents();
	void    doEvent(sf::Keyboard::Key key);
	void    onNextSprite();
	void    onPrevSprite();
	void    onRemoveSprite();
	void    onZoomIn();
	void    onZoomOut();
	void    onSelect();
	void    onSelectAll();
	void    onChangeMode();
	void    onSave();

	SpriteManager           &spriteManager;

	sf::RenderWindow        window;
	sf::Sprite              sprite;
	sf::Texture             texture;
	sf::Rect<int>           textureRect;
	sf::RectangleShape      border;
	sf::Text                mode;
	sf::Font                font;

	unsigned int            spriteIndex;
	float                   scale;

	bool                    fontLoaded;

	using Callback = std::function<void(void)>;

	std::map<sf::Keyboard::Key, Displayer::Callback>    actions;

};


#endif //SFMLDEMO_DISPLAYER_HPP
