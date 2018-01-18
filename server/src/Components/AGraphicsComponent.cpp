//
// Created by romain on 16/01/18.
//

#include <Components/AGraphicsComponent.hpp>

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
