//
// Created by romain on 18/01/18.
//

#include "RemoveEntityCommand.hpp"
#include "ShotMovementComponent.hpp"

Component::ShotMovementComponent::ShotMovementComponent(Engine::Entity *parentEntity, double speed,
														unsigned int lifetime) :
		AMovementComponent(parentEntity), _speed(speed), _lifetime(lifetime)
{
}

void Component::ShotMovementComponent::update() noexcept
{
	this->_lastMove.x = this->_speed * cos(this->_parentEntity->getTransformComponent().getRotationRadians());
	this->_lastMove.y = this->_speed * sin(this->_parentEntity->getTransformComponent().getRotationRadians());

	this->_parentEntity->getTransformComponent().getPosition().x += this->_lastMove.x;
	this->_parentEntity->getTransformComponent().getPosition().y += this->_lastMove.y;
	this->_lifetime--;
	if (this->_lifetime == 0) {
		this->sendToParentEntity(Engine::Mediator::Message::DEATH);
	}
}

Engine::AComponent *Component::ShotMovementComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	ShotMovementComponent *newComp = new ShotMovementComponent(parentEntity, this->_speed, this->_lifetime);

	*newComp = *this;

	return newComp;
}
