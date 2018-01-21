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
		friend class ZoneComponent;
	public:
		enum Direction
		{
			TOP,
			RIGHT,
			BOTTOM,
			LEFT,
			UNDEFINED
		};

		explicit APhysicsComponent(Engine::Entity *entity, const Engine::Hitbox &hitbox);
		~APhysicsComponent() override = default;

		int getCollisionDamages() const;
		void setCollisionDamages(int collisionDamages);
		bool getCollision(Direction) const;
		void setOBB();

		// handle methods
		virtual void handleCheckCollision(Engine::Mediator::Message messageType, Engine::AComponent *sender);
		void handleMove(Engine::Mediator::Message messageType, Engine::AComponent *sender);

		// default collision methods
		void blockingCollision(APhysicsComponent &other);
		void damagingCollision(APhysicsComponent &other);

		APhysicsComponent &operator=(const APhysicsComponent &other);
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
			bool checkIntersection(APhysicsComponent &);
			bool checkIntersection(const Vector2d &point);
		};

	protected:
		const Engine::Hitbox _hitbox;
		std::unique_ptr<OBB> _orientedBoundingBox;
		int _collisionDamages;
		std::unordered_map<Engine::Hitbox::Type, std::function<void(APhysicsComponent &)>> _collisionHandlers;
		bool _collisions[UNDEFINED];

		void triggerCollision(APhysicsComponent &other);
		void setCollision(Direction, bool);
		void resetCollisions();
	};
}

#endif //RTYPE_APHYSICSCOMPONENT_HPP