//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_HITBOX_HPP
#define RTYPE_HITBOX_HPP

#include <Common/Vector2d.hpp>

namespace Engine {
	class Hitbox
	{
	public:
		enum Type
		{
			ENEMY,
			PLAYER,
			ENEMY_SHOT,
			PLAYER_SHOT,
			NEUTRAL,
			ZONE,
			CAMERA
		};

		Type _type;
		Vector2d _relativeStartPos;
		Vector2d _relativeRange;

		Hitbox() = delete;
		Hitbox(Type type, const Vector2d &relativeStartPos, const Vector2d &relativeRange);
		Hitbox(const Hitbox &other);
		~Hitbox() = default;
	};
}

#endif //RTYPE_HITBOX_HPP
