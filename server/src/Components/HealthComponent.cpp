//
// Created by romain on 19/01/18.
//

#include "HealthComponent.hpp"
#include "APhysicsComponent.hpp"
#include "RemoveEntityCommand.hpp"

Component::HealthComponent::HealthComponent(Engine::Entity *parentEntity, Engine::World *world, int health,
											bool godMode, bool instantDeath) :
		AComponent(parentEntity), _world(world), _godMode(godMode), _health(health), _maxHealth(health),
		_instantDeath(instantDeath)
{
	this->_validMessageTypes[Engine::Mediator::Message::GET_IMPACT_DAMAGES] = std::bind(
			&HealthComponent::handleGetImpactDamages,
			this, std::placeholders::_1,
			std::placeholders::_2);
	this->_validMessageTypes[Engine::Mediator::Message::HIT] = std::bind(
			&HealthComponent::handleHit,
			this, std::placeholders::_1,
			std::placeholders::_2);
	this->_validMessageTypes[Engine::Mediator::Message::DEATH] = std::bind(
			&HealthComponent::handleDeath,
			this, std::placeholders::_1,
			std::placeholders::_2);
}

void Component::HealthComponent::update() noexcept
{
}

void Component::HealthComponent::takeDamage(int damages) noexcept
{
	if (!this->_godMode) {
		this->_health -= (this->_instantDeath) ? this->_health : damages;
		if (this->_health <= 0) {
			this->sendToAll(Engine::Mediator::Message::DEATH);
			this->_parentEntity->addCommand(new Engine::Commands::RemoveEntityCommand(*this->_world,
																					  this->_parentEntity->getId()));
		}
	}
}

void Component::HealthComponent::handleGetImpactDamages(Engine::Mediator::Message, Engine::AComponent *sender) noexcept
{
	if (APhysicsComponent *physics = dynamic_cast<APhysicsComponent *>(sender)) {
		physics->setCollisionDamages(this->_maxHealth);
	}
}

void Component::HealthComponent::handleHit(Engine::Mediator::Message, Engine::AComponent *sender) noexcept
{
	if (APhysicsComponent *physics = dynamic_cast<APhysicsComponent *>(sender)) {
		this->takeDamage(physics->getCollisionDamages());
	}
}

void Component::HealthComponent::handleDeath(Engine::Mediator::Message, Engine::AComponent *) noexcept
{
	this->_health = 0;
	this->_parentEntity->addCommand(new Engine::Commands::RemoveEntityCommand(*this->_world,
																			  this->_parentEntity->getId()));
}

Engine::AComponent *
Component::HealthComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	Component::HealthComponent *healthComponent = new Component::HealthComponent(parentEntity, this->_world,
																				 this->_maxHealth, this->_godMode,
																				 this->_instantDeath);

	*healthComponent = *this;

	return healthComponent;
}

Component::HealthComponent &Component::HealthComponent::operator=(const Component::HealthComponent &other)
{
	for (unsigned int i = 0; i < other._mediators.size() - 1; ++i) {
		this->registerToMediator(other._mediators[i]);
	}
	return *this;
}