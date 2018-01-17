//
// Created by romain on 16/01/18.
//

#include <Components/AGraphicsComponent.hpp>

Component::AGraphicsComponent::AGraphicsComponent(Engine::Entity *parentEntity) :
		AComponent(parentEntity)
{
}

bool Component::AGraphicsComponent::isInArea(float xPos, float yPos, float xRange, float yRange)
{
	if (this->_parentEntity->getTransformComponent().getPosition().x > xPos &&
		this->_parentEntity->getTransformComponent().getPosition().x < xPos + xRange &&
		this->_parentEntity->getTransformComponent().getPosition().y > yPos &&
		this->_parentEntity->getTransformComponent().getPosition().y < yPos + yRange) {
		return true;
	}
	return false;
}
