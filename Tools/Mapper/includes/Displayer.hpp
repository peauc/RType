/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#ifndef SFMLDEMO_DISPLAYER_HPP
#define SFMLDEMO_DISPLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
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
	void    onNextSprite();
	void    onPrevSprite();
	void    onRemoveSprite();
	void    onZoomIn();
	void    onZoomOut();
	void    onSelect();
	void    onSelectAll();
	void    onChangeMode();
	void    onSave();
	void	onChangeEqualize();

	std::string		getMode() const;

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

	using Callback = void (Displayer::*) (void);

	std::array<Displayer::Callback, sf::Keyboard::KeyCount>	actions;

};


#endif //SFMLDEMO_DISPLAYER_HPP
