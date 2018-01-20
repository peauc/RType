//
// Created by romain on 12/01/18.
//

#ifndef RTYPE_VECTOR2D_HPP
#define RTYPE_VECTOR2D_HPP

struct Vector2d
{
	double x;
	double y;

	Vector2d() = default;
	Vector2d(double x, double y) : x(x), y(y)
	{};
};

#endif //RTYPE_VECTOR2D_HPP
