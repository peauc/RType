/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_ISPRITE_HPP
# define RTYPE_ISPRITE_HPP

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
	virtual void 	setPosX(int x) = 0;
	virtual void 	setPosY(int y) = 0;
	virtual void	updateAnimation() = 0;
};

#endif //RTYPE_ISPRITE_HPP
