//
// Created by romain on 19/01/18.
//

#ifndef RTYPE_HEALTHCOMPONENT_HPP
#define RTYPE_HEALTHCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/World.hpp>

namespace Component {
	class HealthComponent : public Engine::AComponent
	{
	public:
		HealthComponent(Engine::Entity *parentEntity, Engine::World *world, int health, bool godMode,
						bool instantDeath);
		~HealthComponent() override = default;

		void update() noexcept override;

		void takeDamage(int damages) noexcept;

		// handle methods
		void handleGetImpactDamages(Engine::Mediator::Message messageType, Engine::AComponent *sender) noexcept;
		void handleHit(Engine::Mediator::Message messageType, Engine::AComponent *sender) noexcept;

		Engine::AComponent *clone(Engine::Entity *parentEntity) const noexcept override;
	private:
		Engine::World *_world;
		bool _godMode;
		int _health;
		int _maxHealth;
		bool _instantDeath;
	};
}

#endif //RTYPE_HEALTHCOMPONENT_HPP
