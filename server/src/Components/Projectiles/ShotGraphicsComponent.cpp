//
// Created by romain on 18/01/18.
//

#include "ShotGraphicsComponent.hpp"

Component::ShotGraphicsComponent::ShotGraphicsComponent(Engine::Entity *parentEntity,
														ResourcesLoader *resourceLoader,
														unsigned char travelAnimationId,
														unsigned char impactAnimationId)
		: AGraphicsComponent(parentEntity, resourceLoader)
{
	this->_animationIds.push_back(travelAnimationId);
	this->_animationIds.push_back(impactAnimationId);
	this->_currentAnimationId = travelAnimationId;

	if (this->setHitbox()) {
		std::cerr << "Missing ressource" << std::endl;
	}

	this->_validMessageTypes[Engine::Mediator::Message::DEATH] = std::bind(&ShotGraphicsComponent::handleImpact,
																		   this, std::placeholders::_1,
																		   std::placeholders::_2);
}

void Component::ShotGraphicsComponent::update() noexcept
{
	this->sendToAll(Engine::Mediator::Message::GRAPHICS_REGISTERING);
}

void Component::ShotGraphicsComponent::handleImpact(Engine::Mediator::Message, Engine::AComponent *) noexcept
{
	this->_isAlive = false;
	if (this->_animationIds.size() == 2) {
		this->_currentAnimationId = this->_animationIds[1];
	}
}

Engine::AComponent *Component::ShotGraphicsComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	ShotGraphicsComponent *newComp = new ShotGraphicsComponent(parentEntity, this->_resourceLoader, 0, 0);

	*newComp = *this;

	return newComp;
}
