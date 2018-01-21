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

		int getCollisionDamages() const noexcept;
		void setCollisionDamages(int collisionDamages) noexcept;
		bool getCollision(Direction) const noexcept;
		void setOBB() noexcept;

		// handle methods
		virtual void handleCheckCollision(Engine::Mediator::Message messageType, Engine::AComponent *sender) noexcept;
		void handleMove(Engine::Mediator::Message messageType, Engine::AComponent *sender) noexcept;

		// default collision methods
		void blockingCollision(APhysicsComponent &other) noexcept;
		void damagingCollision(APhysicsComponent &other) noexcept;

		// operator overloads
		APhysicsComponent &operator=(const APhysicsComponent &other) noexcept;

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
			bool checkIntersection(APhysicsComponent &) noexcept;
			bool checkIntersection(const Vector2d &point) noexcept;
		};

	protected:
		const Engine::Hitbox _hitbox;
		std::unique_ptr<OBB> _orientedBoundingBox;
		int _collisionDamages;
		std::unordered_map<Engine::Hitbox::Type, std::function<void(APhysicsComponent &)>> _collisionHandlers;
		bool _collisions[UNDEFINED];

		void triggerCollision(APhysicsComponent &other) noexcept;
		void setCollision(Direction, bool) noexcept;
		void resetCollisions() noexcept;
	};
}

#endif //RTYPE_APHYSICSCOMPONENT_HPP