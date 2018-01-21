//
// Created by romain on 18/01/18.
//

#include <Components/Projectiles/ShotGraphicsComponent.hpp>

Component::ShotGraphicsComponent::ShotGraphicsComponent(Engine::Entity *parentEntity,
														RessourcesLoader *resourceLoader,
														unsigned char travelAnimationId,
														unsigned char impactAnimationId)
		: AGraphicsComponent(parentEntity, resourceLoader)
{
	this->_animationIds.push_back(travelAnimationId);
	this->_animationIds.push_back(impactAnimationId);
	this->_currentAnimationId = travelAnimationId;

	this->_relativeStartPos.x = -300;
	this->_relativeStartPos.y = -100;
	this->_relativeRange.x = 600;
	this->_relativeRange.y = 200;

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