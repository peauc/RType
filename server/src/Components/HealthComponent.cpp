//
// Created by romain on 19/01/18.
//

#include <Components/HealthComponent.hpp>

Component::HealthComponent::HealthComponent(Engine::Entity *parentEntity, int health, bool godMode) :
		AComponent(parentEntity), _godMode(godMode), _health(_health)
{
}

void Component::HealthComponent::update()
{
}

void Component::HealthComponent::takeDamage(unsigned int damages)
{
}
