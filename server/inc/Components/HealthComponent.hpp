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
		HealthComponent(Engine::Entity *parentEntity, int health, bool godMode);
		~HealthComponent() override = default;

		void update() override;

		void takeDamage(unsigned int damages);
	private:
		bool _godMode;
		int _health;
	};
}

#endif //RTYPE_HEALTHCOMPONENT_HPP
