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
	virtual void	selectSprite(uint32_t tileNumber, uint32_t line) = 0;
};

#endif //RTYPE_ISPRITE_HPP
