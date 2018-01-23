/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_ISPRITE_HPP
# define RTYPE_ISPRITE_HPP

# include <functional>

class	ClientGame;

class	ISprite
{
public:
	virtual ~ISprite() = default;

	virtual void	selectSprite(unsigned int posX,
					 unsigned int posY,
					 unsigned int sizeX,
					 unsigned int sizeY) = 0;
	virtual void	selectSprite(uint32_t tileNb, uint32_t lineNb) = 0;
	virtual int 	getPosX() const = 0;
	virtual int 	getPosY() const = 0;
	virtual void	setPos(int x, int y) = 0;
	virtual void 	setPosX(int x) = 0;
	virtual void 	setPosY(int y) = 0;
	virtual uint32_t getAnimationId() const = 0;
	virtual void	setAnimationId(uint32_t id) = 0;
	virtual void	updateAnimation() = 0;
	virtual void	onClick() = 0;
	virtual void	setOnClick(std::function<void()> f) = 0;
	virtual bool	isWaitingToBeDeleted() const = 0;
	virtual bool	isAnimationRepeating() const = 0;
	virtual void	setRepeatAnimation(bool repeat) = 0;
};

#endif //RTYPE_ISPRITE_HPP
