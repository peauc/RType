//
// Created by romain on 18/01/18.
//

#include <Components/Projectiles/ShotGraphicsComponent.hpp>

Component::ShotGraphicsComponent::ShotGraphicsComponent(Engine::Entity *parentEntity,
														unsigned char travelAnimationId,
														unsigned char impactAnimationId)
		: AGraphicsComponent(parentEntity)
{
	this->_animationIds.push_back(travelAnimationId);
	this->_animationIds.push_back(impactAnimationId);
	this->_currentAnimationId = travelAnimationId;

	this->_validMessageTypes[Engine::Mediator::Message::DEATH] = std::bind(&ShotGraphicsComponent::handleImpact,
																		   this, std::placeholders::_1,
																		   std::placeholders::_2);
}

Component::ShotGraphicsComponent::ShotGraphicsComponent(Engine::Entity *parentEntity,
														RessourcesLoader *resourceLoader,
														unsigned char travelAnimationId,
														unsigned char impactAnimationId)
		: AGraphicsComponent(parentEntity, resourceLoader)
{
	this->_animationIds.push_back(travelAnimationId);
	this->_animationIds.push_back(impactAnimationId);
	this->_currentAnimationId = travelAnimationId;

	this->_validMessageTypes[Engine::Mediator::Message::DEATH] = std::bind(&ShotGraphicsComponent::handleImpact,
																		   this, std::placeholders::_1,
																		   std::placeholders::_2);
}

void Component::ShotGraphicsComponent::update()
{
	this->sendToAll(Engine::Mediator::Message::GRAPHICS_REGISTERING);
}

void Component::ShotGraphicsComponent::handleImpact(Engine::Mediator::Message, Engine::AComponent *)
{
	this->_isAlive = false;
	if (this->_animationIds.size() == 2) {
		this->_currentAnimationId = this->_animationIds[1];
	}
}