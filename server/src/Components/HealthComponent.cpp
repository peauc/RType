//
// Created by romain on 19/01/18.
//

#include <Components/HealthComponent.hpp>
#include <Components/Abstracts/APhysicsComponent.hpp>

Component::HealthComponent::HealthComponent(Engine::Entity *parentEntity, int health, bool godMode, bool instantDeath) :
		AComponent(parentEntity), _godMode(godMode), _health(health), _instantDeath(instantDeath), _maxHealth(health)
{
}

void Component::HealthComponent::update()
{
}

void Component::HealthComponent::takeDamage(int damages)
{
	if (!this->_godMode) {
		this->_health -= (this->_instantDeath) ? this->_health : damages;
		if (this->_health < 0) {
			this->sendToAll(Engine::Mediator::Message::DEATH);
		}
	}
}

int Component::HealthComponent::getHealth() const
{
	return this->_health;
}

void Component::HealthComponent::handleGetImpactDamages(Engine::Mediator::Message messageType, Engine::AComponent *sender)
{
	if (APhysicsComponent *physics = dynamic_cast<APhysicsComponent *>(sender)) {
		physics->setCollisionDamages(this->_maxHealth);
	}
}

void Component::HealthComponent::handleHit(Engine::Mediator::Message messageType, Engine::AComponent *sender)
{
	if (APhysicsComponent *physics = dynamic_cast<APhysicsComponent *>(sender)) {
		this->takeDamage(physics->getCollisionDamages());
	}
}
