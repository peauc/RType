//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_APHYSICSCOMPONENT_HPP
#define RTYPE_APHYSICSCOMPONENT_HPP

#include <cmath>
#include <Engine/AComponent.hpp>
#include <Engine/Hitbox.hpp>
#include <Engine/TransformComponent.hpp>

namespace Component {
	class APhysicsComponent : public Engine::AComponent
	{
	public:
		explicit APhysicsComponent(Engine::Entity *entity, Engine::Hitbox hitbox);
		~APhysicsComponent() override = default;

	protected:
		struct OBB
		{
			Vector2d center;
			Vector2d p1;
			Vector2d p2;
			Vector2d p3;
			Vector2d p4;

			OBB() = default;
			OBB(const Engine::TransformComponent &transformComponent, const Engine::Hitbox &hitbox);
			bool checkIntersection(const OBB &other);
			bool checkIntersection(const Vector2d &point);
		};

	protected:
		Engine::Hitbox _hitbox;
		OBB _orientedBoundingBox;

	protected:
		virtual void triggerCollision(APhysicsComponent &other) = 0;
	};
}

#endif //RTYPE_APHYSICSCOMPONENT_HPP