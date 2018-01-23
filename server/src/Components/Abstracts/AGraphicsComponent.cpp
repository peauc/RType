//
// Created by romain on 16/01/18.
//

#include "AGraphicsComponent.hpp"
#include "ResourcesLoader.hpp"

Component::AGraphicsComponent::AGraphicsComponent(Engine::Entity *parentEntity, ResourcesLoader *resourceLoader)
		: AComponent(parentEntity), _resourceLoader(resourceLoader), _isHit(false), _isAlive(true)
{
}

int Component::AGraphicsComponent::setHitbox()
{
	if (this->_resourceLoader == nullptr ||
		this->_resourceLoader->getAnimations().count(this->_currentAnimationId) == 0) {
		return 1;
	}
	const ResourcesLoader::Animation animation = this->_resourceLoader->getAnimations().at(this->_currentAnimationId);

	this->_relativeStartPos.x = -animation.at(0).width * 5;
	this->_relativeStartPos.y = -animation.at(0).height * 5;
	this->_relativeRange.x = animation.at(0).width * 10;
	this->_relativeRange.y = animation.at(0).height * 10;
	return 0;
}

bool Component::AGraphicsComponent::isInArea(double xPos, double yPos, double xRange, double yRange) noexcept
{
	return (this->_parentEntity->getTransformComponent().getPosition().x >= xPos &&
			this->_parentEntity->getTransformComponent().getPosition().x <= xPos + xRange &&
			this->_parentEntity->getTransformComponent().getPosition().y >= yPos &&
			this->_parentEntity->getTransformComponent().getPosition().y <= yPos + yRange);
}

double Component::AGraphicsComponent::getRelativeXPos(double xPos, double xRange) noexcept
{
	return (this->_parentEntity->getTransformComponent().getPosition().x + this->_relativeStartPos.x - xPos) / xRange *
		   100;
}

double Component::AGraphicsComponent::getRelativeYPos(double yPos, double yRange) noexcept
{
	return (this->_parentEntity->getTransformComponent().getPosition().y + this->_relativeStartPos.y - yPos) / yRange *
		   100;
}

ResourcesLoader *Component::AGraphicsComponent::getResourceLoader() const noexcept
{
	return _resourceLoader;
}

void Component::AGraphicsComponent::setResourceLoader(ResourcesLoader *_resourceLoader) noexcept
{
	AGraphicsComponent::_resourceLoader = _resourceLoader;
}

unsigned char Component::AGraphicsComponent::getCurrentAnimationId() const noexcept
{
	return _currentAnimationId;
}

bool Component::AGraphicsComponent::isHit() const noexcept
{
	return _isHit;
}

void Component::AGraphicsComponent::setIsHit(bool _isHit) noexcept
{
	AGraphicsComponent::_isHit = _isHit;
}

bool Component::AGraphicsComponent::isAlive() const noexcept
{
	return _isAlive;
}

void Component::AGraphicsComponent::setIsAlive(bool _isAlive) noexcept
{
	AGraphicsComponent::_isAlive = _isAlive;
}

const Vector2d &Component::AGraphicsComponent::getRelativeStartPos() const noexcept
{
	return this->_relativeStartPos;
}

const Vector2d &Component::AGraphicsComponent::getRange() const noexcept
{
	return this->_relativeRange;
}

Component::AGraphicsComponent &
Component::AGraphicsComponent::operator=(const Component::AGraphicsComponent &other) noexcept
{
	this->_relativeRange = other._relativeRange;
	this->_relativeStartPos = other._relativeStartPos;
	this->_currentAnimationId = other._currentAnimationId;
	this->_resourceLoader = other._resourceLoader;
	this->_isHit = other._isHit;
	this->_animationIds = other._animationIds;
	this->_observers = other._observers;
	for (unsigned int i = 0; i < other._mediators.size() - 1; ++i) {
		this->registerToMediator(other._mediators[i]);
	}

	return *this;
}


