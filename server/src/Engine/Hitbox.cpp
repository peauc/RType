//
// Created by romain on 19/01/18.
//

#include <Engine/Hitbox.hpp>

Engine::Hitbox::Hitbox(Engine::Hitbox::Type type, const Vector2d &relativeStartPos, const Vector2d &relativeRange) :
		_type(type), _relativeStartPos(relativeStartPos), _relativeRange(relativeRange)
{
}