/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#ifndef MAPPER_TILEEQUALIZER_HPP
#define MAPPER_TILEEQUALIZER_HPP

#include <vector>
#include "Sprite.hpp"

class TileEqualizer {

public:

	TileEqualizer(std::vector<Sprite>	&sprites);
	~TileEqualizer() = default;
	TileEqualizer(const TileEqualizer&) = delete;
	TileEqualizer    operator=(const TileEqualizer&) = delete;

	void	equalize();

private:

	void	equalizeWidth(unsigned int start, unsigned int end);
	void	equalizeHeight(unsigned int start, unsigned int end);

	unsigned int	getBiggestWidth(unsigned int start,
									unsigned int end) const;

	std::vector<Sprite>		&sprites;

};


#endif //MAPPER_TILEEQUALIZER_HPP
