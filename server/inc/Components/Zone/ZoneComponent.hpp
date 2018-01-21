//
// Created by romain on 21/01/18.
//

#ifndef RTYPE_ZONECOMPONENT_HPP
#define RTYPE_ZONECOMPONENT_HPP

#include "AComponent.hpp"
#include "World.hpp"
#include "APhysicsComponent.hpp"

namespace Component {
	class ZoneComponent : public Component::APhysicsComponent
	{
	public:
		explicit ZoneComponent(Engine::Entity *parentEntity, const Engine::Hitbox &, Engine::World *parentWorld);
		~ZoneComponent() override = default;

		void update() noexcept override;
		void trigger() noexcept;

		void addEntity(std::unique_ptr<Engine::Entity> entity) noexcept;

		// handle methods
		void handleCheckCollision(Engine::Mediator::Message, AComponent *sender) noexcept override;
	private:
		Engine::World *_parentWorld;
		std::vector<std::unique_ptr<Engine::Entity>> _entities;
	};
}

#endif //RTYPE_ZONECOMPONENT_HPP
