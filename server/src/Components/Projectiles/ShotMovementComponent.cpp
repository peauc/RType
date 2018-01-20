//
// Created by romain on 18/01/18.
//

#include <Components/Projectiles/ShotMovementComponent.hpp>

Component::ShotMovementComponent::ShotMovementComponent(Engine::Entity *parentEntity, double speed) :
		AMovementComponent(parentEntity), _speed(speed)
{

}

void Component::ShotMovementComponent::update()
{
	this->_parentEntity->getTransformComponent().getPosition().x += this->_speed * cos(this->_parentEntity->getTransformComponent().getRotationRadians());
	this->_parentEntity->getTransformComponent().getPosition().y += this->_speed * sin(this->_parentEntity->getTransformComponent().getRotationRadians());
}