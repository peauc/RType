//
// Created by romain on 12/01/18.
//

#ifndef RTYPE_TRANSFORMCOMPONENT_HPP
#define RTYPE_TRANSFORMCOMPONENT_HPP

#include <Common/Vector2d.hpp>
#include "AComponent.hpp"

namespace Engine {
	class TransformComponent : public AComponent
	{
	public:
		explicit TransformComponent(Entity *parentEntity);
		~TransformComponent() override = default;

		void update() override;

		Vector2d &getPosition();
		void setPosition(Vector2d &_position);
		Vector2d &getRotation();
		void setRotation(Vector2d &_rotation);

	private:
		Vector2d _position;
		Vector2d _rotation;
	};
}

#endif //RTYPE_TRANSFORMCOMPONENT_HPP
