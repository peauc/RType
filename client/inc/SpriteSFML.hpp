/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_SPRITESFML_HPP_
# define RTYPE_SPRITESFML_HPP_

# include <SFML/Graphics/Sprite.hpp>
# include <SFML/Graphics/Texture.hpp>
# include "ISprite.hpp"

class SpriteSFML : public ISprite
{
public:
	explicit SpriteSFML(const std::string &fileName,
			    unsigned int sizeTileX, unsigned int sizeTileY);
	SpriteSFML(const SpriteSFML &)  noexcept;
	SpriteSFML &operator=(const SpriteSFML &) noexcept;
	~SpriteSFML() override = default;
	
	void			applyTexture() noexcept;
	const sf::Sprite	&getSprite() const noexcept;
	void	selectSprite(unsigned int posX,
				 unsigned int posY,
				 unsigned int sizeX,
				 unsigned int sizeY) noexcept override;
	void	selectSprite(uint32_t tileNumber,
				 uint32_t line) noexcept override;

private:
	sf::Sprite	_sprite;
	sf::Texture	_texture;
	unsigned int	_sizeTileX;
	unsigned int	_sizeTileY;
};

#endif // !RTYPE_SPRITESFML_HPP_