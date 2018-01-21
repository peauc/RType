//
// Created by romain on 12/01/18.
//

#ifndef RTYPE_TRANSFORMCOMPONENT_HPP
#define RTYPE_TRANSFORMCOMPONENT_HPP

#include <cmath>
#include "Vector2d.hpp"
#include "AComponent.hpp"

namespace Engine {
	class TransformComponent : public AComponent
	{
	public:
		explicit TransformComponent(Entity *parentEntity);
		~TransformComponent() override = default;

		void update() noexcept override;

		Vector2d &getPosition() noexcept;
		const Vector2d &getPosition() const noexcept;
		void setPosition(Vector2d &_position) noexcept;
		double getRotationRadians() const noexcept;
		double getRotation() const noexcept;
		void setRotation(double _rotation) noexcept;

	private:
		Vector2d _position;
		double _rotation;
		double _rotationRadians;
	};
}

#endif //RTYPE_TRANSFORMCOMPONENT_HPP