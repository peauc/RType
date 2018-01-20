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
		friend class CameraZoneComponent;
	public:
		enum Direction
		{
			TOP,
			RIGHT,
			BOTTOM,
			LEFT,
			UNDEFINED
		};

		explicit APhysicsComponent(Engine::Entity *entity, Engine::Hitbox hitbox);
		~APhysicsComponent() override = default;

		int getCollisionDamages() const;
		void setCollisionDamages(int collisionDamages);
		bool getCollision(Direction) const;
		void setOBB();

		// handle methods
		virtual void handleCheckCollision(Engine::Mediator::Message messageType, Engine::AComponent *sender);

		// default collision methods
		void blockingCollision(APhysicsComponent &other);
		void damagingCollision(APhysicsComponent &other);
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
			bool checkIntersection(const OBB &other, APhysicsComponent &);
			bool checkIntersection(const Vector2d &point);
		};

	protected:
		Engine::Hitbox _hitbox;
		OBB _orientedBoundingBox;
		int _collisionDamages;
		std::unordered_map<Engine::Hitbox::Type, std::function<void(APhysicsComponent &)>> _collisionHandlers;
		bool _collisions[UNDEFINED];

		void triggerCollision(APhysicsComponent &other);
		void setCollision(Direction, bool);
		void resetCollisions();
	};
}

#endif //RTYPE_APHYSICSCOMPONENT_HPP