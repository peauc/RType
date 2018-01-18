//
// Created by romain on 16/01/18.
//

#include <Components/Abstracts/AGraphicsComponent.hpp>

Component::AGraphicsComponent::AGraphicsComponent(Engine::Entity *parentEntity) : AComponent(parentEntity)
{
}

Component::AGraphicsComponent::AGraphicsComponent(Engine::Entity *parentEntity, RessourcesLoader *resourceLoader)
		: AComponent(parentEntity), _resourceLoader(resourceLoader)
{
}

bool Component::AGraphicsComponent::isInArea(float xPos, float yPos, float xRange, float yRange)
{
	return (this->_parentEntity->getTransformComponent().getPosition().x >= xPos &&
			this->_parentEntity->getTransformComponent().getPosition().x <= xPos + xRange &&
			this->_parentEntity->getTransformComponent().getPosition().y >= yPos &&
			this->_parentEntity->getTransformComponent().getPosition().y <= yPos + yRange);
}

RessourcesLoader *Component::AGraphicsComponent::getResourceLoader() const
{
	return _resourceLoader;
}

void Component::AGraphicsComponent::setResourceLoader(RessourcesLoader *_resourceLoader)
{
	AGraphicsComponent::_resourceLoader = _resourceLoader;
}

unsigned int Component::AGraphicsComponent::getCurrentAnimationId() const
{
	return _currentAnimationId;
}

bool Component::AGraphicsComponent::isHit() const
{
	return _isHit;
}

void Component::AGraphicsComponent::setIsHit(bool _isHit)
{
	AGraphicsComponent::_isHit = _isHit;
}

bool Component::AGraphicsComponent::isAlive() const
{
	return _isAlive;
}

void Component::AGraphicsComponent::setIsAlive(bool _isAlive)
{
	AGraphicsComponent::_isAlive = _isAlive;
}
