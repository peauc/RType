/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#ifndef MAPPER_SPRITE_HPP
#define MAPPER_SPRITE_HPP


class Sprite
{
public:

	Sprite();
	~Sprite() = default;
	Sprite(const Sprite &obj);
	Sprite  &operator=(const Sprite &obj);

	void    setMinX(unsigned int minX);
	void    setMinY(unsigned int minY);
	void    setMaxX(unsigned int maxX);
	void    setMaxY(unsigned int maxY);
	void    setInitialized(bool state);

	unsigned int    getMinX() const;
	unsigned int    getMinY() const;
	unsigned int    getWidth() const;
	unsigned int    getHeight() const;

private:

	unsigned int    minX;
	unsigned int    minY;
	unsigned int    maxX;
	unsigned int    maxY;
	bool            initialized;
};


#endif //MAPPER_SPRITE_HPP
