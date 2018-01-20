/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#ifndef MAPPER_PIXELSARRAY_HPP
#define MAPPER_PIXELSARRAY_HPP

#include <vector>

class PixelsArray {

public:

	PixelsArray(std::size_t width, std::size_t height, bool init);
	~PixelsArray() = default;
	PixelsArray(const PixelsArray &obj);
	PixelsArray		&operator=(const PixelsArray &obj);

	std::vector<bool>::reference	at(unsigned int x, unsigned int y);

	bool	outOfRange(unsigned int x, unsigned int y) const;

	std::size_t		getWidth() const;
	std::size_t		getHeight() const;

private:

	std::vector<bool>	pixels;
	std::size_t			width;
	std::size_t			height;
};


#endif //MAPPER_PIXELSARRAY_HPP
