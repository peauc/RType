//
// Created by romain on 17/01/18.
//

#include <Components/Player/PlayerGraphicsComponent.hpp>
#include <iostream>

Component::PlayerGraphicsComponent::PlayerGraphicsComponent(Engine::Entity *parentEntity,
															RessourcesLoader *resourceLoader) :
		AGraphicsComponent(parentEntity, resourceLoader)
{
	switch (parentEntity->getId()) {
		case 0:
			this->_animationIds.push_back(8);
			this->_animationIds.push_back(7);
			this->_animationIds.push_back(5);
			this->_animationIds.push_back(6);
			this->_animationIds.push_back(4);
			break;
		case 1:
			this->_animationIds.push_back(20);
			this->_animationIds.push_back(19);
			this->_animationIds.push_back(17);
			this->_animationIds.push_back(18);
			this->_animationIds.push_back(16);
			break;
		case 2:
			this->_animationIds.push_back(14);
			this->_animationIds.push_back(13);
			this->_animationIds.push_back(11);
			this->_animationIds.push_back(12);
			this->_animationIds.push_back(10);
			break;
		case 3:
			this->_animationIds.push_back(26);
			this->_animationIds.push_back(25);
			this->_animationIds.push_back(23);
			this->_animationIds.push_back(24);
			this->_animationIds.push_back(23);
			break;
		default:
			break;
	}
	this->_currentAnimationId = this->_animationIds[0];

	// set handle methods
	this->_validMessageTypes[Engine::Mediator::Message::DEATH] = std::bind(&PlayerGraphicsComponent::handleDeath,
																		   this, std::placeholders::_1,
																		   std::placeholders::_2);
	this->_validMessageTypes[Engine::Mediator::Message::HIT] = std::bind(&PlayerGraphicsComponent::handleHit,
																		 this, std::placeholders::_1,
																		 std::placeholders::_2);
}

void Component::PlayerGraphicsComponent::update()
{
	std::cout << "Updating graphics" << std::endl;
	this->sendToAll(Engine::Mediator::Message::GRAPHICS_REGISTERING);
}

void Component::PlayerGraphicsComponent::handleDeath(Engine::Mediator::Message messageType, Engine::AComponent *sender)
{
	this->_isHit = true;
}

void Component::PlayerGraphicsComponent::handleHit(Engine::Mediator::Message messageType, Engine::AComponent *sender)
{
	this->_isAlive = false;
}
