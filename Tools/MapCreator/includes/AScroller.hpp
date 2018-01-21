/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_ASCROLLER_HPP
#define MAPCREATOR_ASCROLLER_HPP

#include "IScroller.hpp"

class AScroller : public IScroller {

public:

	AScroller();
	~AScroller() = default;
	AScroller(const AScroller &obj);
	AScroller	&operator=(const AScroller &obj);

	enum Scroll {
		HORIZONTAL,
		VERTICAL
	};

protected:

	Scroll		scroll;
	float		scrollSpeed;
	int			scrollValue;
	int 		maxScroll;
};


#endif //MAPCREATOR_ASCROLLER_HPP
