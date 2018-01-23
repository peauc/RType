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
# include "Graphic/ASprite.hpp"

class SpriteSFML : public ASprite
{
public:
	SpriteSFML() noexcept;
	SpriteSFML(const std::string &fileName,
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
	void	setAnimationVector(const std::vector<sf::Texture>
				       &vector, bool repeat) noexcept;
	void	updateAnimation() noexcept override;
	void	setPosX(int x) noexcept override;
	void	setPosY(int y) noexcept override;
	void	setPos(int x, int y) noexcept override;

private:
	sf::Sprite	_sprite;
	sf::Texture	_texture;
	unsigned int	_sizeTileX;
	unsigned int	_sizeTileY;
	std::vector<sf::Texture> _animationVector;
};

#endif // !RTYPE_SPRITESFML_HPP_