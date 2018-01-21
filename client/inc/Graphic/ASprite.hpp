/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_ASPRITE_HPP_
# define RTYPE_ASPRITE_HPP_

# include "ISprite.hpp"

class ASprite : public ISprite
{
public:
	ASprite() noexcept;
	ASprite(const ASprite &) noexcept;
	ASprite &operator=(const ASprite &) noexcept;
	~ASprite() override = default;

	void	selectSprite(unsigned int posX,
				 unsigned int posY,
				 unsigned int sizeX,
				 unsigned int sizeY) override = 0;
	void	selectSprite(uint32_t tileNb, uint32_t lineNb) override = 0;
	void	updateAnimation() override = 0;
	int	getPosX() const noexcept override;
	int	getPosY() const noexcept override;
	void	setPosX(int x) noexcept override;
	void	setPosY(int y) noexcept override;
	void	setPos(int x, int y) noexcept override;
	void	onClick() override;
	void	setOnClick(std::function<void()>
			       f) noexcept override;

protected:
	int		_posX;
	int		_posY;
	std::function<void()> _onClick;
};

#endif // !RTYPE_ASPRITE_HPP_