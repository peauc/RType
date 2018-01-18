/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#ifndef MAPPER_SPRITEMANAGER_HPP
#define MAPPER_SPRITEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Sprite.hpp"

class SpriteManager {

public:

	SpriteManager() = default;
	~SpriteManager() = default;
	SpriteManager(const SpriteManager&) = delete;
	SpriteManager   &operator=(const SpriteManager&) = delete;

	void    setSprites(const std::vector<Sprite> &sprites);
	void    setSpritesEqualize(const std::vector<Sprite> &sprites);
	void    setImage(const sf::Image &image);
	void    setSpriteSelected(unsigned int index, bool state);
	void    setSaveInfos(const std::string &source,
	                     const std::string &dest,
						 const std::string &execDir);
	void	setAnimationMode(bool state);
	void	setEqualizeSprites(bool state);

	const std::vector<Sprite>	&getSprites() const;
	const sf::Image     		&getImage() const;
	unsigned int        		removeSprite(unsigned int index);

	bool    availableSprites() const;
	bool    spriteIsSelected(unsigned int index) const;
	bool    allSelected() const;
	bool	getAnimationMode() const;
	bool 	getEqualizeSprites() const;

	void    resetSelected();
	void	save();

private:

	void    		saveSprites();
	void    		saveAnimation();
	std::string     jsonFormat(const Sprite &sprite) const;
	std::string     animationFormat() const;
	bool            hasSomethingToSave() const;
	void			removeAnimationSpriteIndex(unsigned int index);

	std::vector<Sprite>     	sprites;
	std::vector<Sprite>     	spritesEqualize;
	std::vector<bool>       	selectedSprites;
	std::vector<unsigned int>	animationSpritesIndex;
	sf::Image               	image;
	std::string             	source;
	std::string             	dest;
	unsigned int            	saveSpriteIndex;
	unsigned int            	saveAnimationIndex;
	bool						animationMode;
	bool						equalizeSprites;
};


#endif //MAPPER_SPRITEMANAGER_HPP
