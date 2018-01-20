//
// Created by romain on 19/01/18.
//

#ifndef RTYPE_HEALTHCOMPONENT_HPP
#define RTYPE_HEALTHCOMPONENT_HPP

#include <Engine/AComponent.hpp>

namespace Component {
	class HealthComponent : public Engine::AComponent
	{
	public:
		HealthComponent(Engine::Entity *parentEntity, int health, bool godMode, bool instantDeath);
		~HealthComponent() override = default;

		void update() override;

		void takeDamage(int damages);

		// handle methods
		void handleGetImpactDamages(Engine::Mediator::Message messageType, Engine::AComponent *sender);
		void handleHit(Engine::Mediator::Message messageType, Engine::AComponent *sender);
	private:
		bool _godMode;
		int _health;
		int _maxHealth;
		bool _instantDeath;
	};
}

#endif //RTYPE_HEALTHCOMPONENT_HPP
