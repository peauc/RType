//
// Created by buis_p on 1/18/18.
//


#include <iostream>
#include "EnemyGraphicsComponent.hpp"

Component::EnemyGraphicsComponent::EnemyGraphicsComponent(Engine::Entity *parentEntity,
															RessourcesLoader *resourceLoader) :
		AGraphicsComponent(parentEntity, resourceLoader)
{
	this->_animationIds.push_back(0);
	this->_currentAnimationId = this->_animationIds[0];

	this->_relativeStartPos.x = -500;
	this->_relativeStartPos.y = -300;
	this->_relativeRange.x = 1000;
	this->_relativeRange.y = 600;

	this->_validMessageTypes[Engine::Mediator::Message::DEATH] = std::bind(&EnemyGraphicsComponent::handleDeath,
																		   this, std::placeholders::_1,
																		   std::placeholders::_2);
	this->_validMessageTypes[Engine::Mediator::Message::HIT] = std::bind(&EnemyGraphicsComponent::handleHit,
																		 this, std::placeholders::_1,
																		 std::placeholders::_2);
}

void Component::EnemyGraphicsComponent::update()
{
	std::cout << "Updating graphics" << std::endl;
	this->sendToAll(Engine::Mediator::Message::GRAPHICS_REGISTERING);
}

void Component::EnemyGraphicsComponent::handleDeath(Engine::Mediator::Message, Engine::AComponent *)
{
	this->_isHit = true;
}

void Component::EnemyGraphicsComponent::handleHit(Engine::Mediator::Message, Engine::AComponent *)
{
	this->_isAlive = false;
}
