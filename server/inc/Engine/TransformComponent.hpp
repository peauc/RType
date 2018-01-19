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
		double getRotation();
		void setRotation(double _rotation);

	private:
		Vector2d _position;
		double _rotation;
	};
}

#endif //RTYPE_TRANSFORMCOMPONENT_HPP