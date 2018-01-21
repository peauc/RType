//
// Created by romain on 21/01/18.
//

#ifndef RTYPE_ZONECOMPONENT_HPP
#define RTYPE_ZONECOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/World.hpp>
#include <Components/Abstracts/APhysicsComponent.hpp>

namespace Component {
	class ZoneComponent : public Component::APhysicsComponent
	{
	public:
		explicit ZoneComponent(Engine::Entity *parentEntity, const Engine::Hitbox &, Engine::World *parentWorld);
		~ZoneComponent() override = default;

		void update() override;
		void trigger();

		void addEntity(std::unique_ptr<Engine::Entity> entity);

		// handle methods
		void handleCheckCollision(Engine::Mediator::Message, AComponent *sender) override;
	private:
		Engine::World *_parentWorld;
		std::vector<std::unique_ptr<Engine::Entity>> _entities;
	};
}

#endif //RTYPE_ZONECOMPONENT_HPP
