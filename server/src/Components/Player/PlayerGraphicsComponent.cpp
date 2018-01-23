//
// Created by romain on 17/01/18.
//

#include "PlayerGraphicsComponent.hpp"
#include "AMovementComponent.hpp"

Component::PlayerGraphicsComponent::PlayerGraphicsComponent(Engine::Entity *parentEntity,
															ResourcesLoader *resourceLoader) :
		AGraphicsComponent(parentEntity, resourceLoader)
{
	switch (parentEntity->getId()) {
		case 0:
			this->_animationIds.push_back(11);
			this->_animationIds.push_back(10);
			this->_animationIds.push_back(9);
			this->_animationIds.push_back(7);
			this->_animationIds.push_back(8);
			break;
		case 1:
			this->_animationIds.push_back(26);
			this->_animationIds.push_back(25);
			this->_animationIds.push_back(24);
			this->_animationIds.push_back(22);
			this->_animationIds.push_back(23);
			break;
		case 2:
			this->_animationIds.push_back(16);
			this->_animationIds.push_back(15);
			this->_animationIds.push_back(14);
			this->_animationIds.push_back(12);
			this->_animationIds.push_back(13);
			break;
		case 3:
			this->_animationIds.push_back(36);
			this->_animationIds.push_back(35);
			this->_animationIds.push_back(34);
			this->_animationIds.push_back(32);
			this->_animationIds.push_back(33);
			break;
		default:
			break;
	}
	this->_currentAnimationId = this->_animationIds[0];

	if (this->setHitbox()) {
		std::cerr << "Missing ressource" << std::endl;
	}

	// set handle methods
	this->_validMessageTypes[Engine::Mediator::Message::DEATH] = std::bind(&PlayerGraphicsComponent::handleDeath,
																		   this, std::placeholders::_1,
																		   std::placeholders::_2);
	this->_validMessageTypes[Engine::Mediator::Message::HIT] = std::bind(&PlayerGraphicsComponent::handleHit,
																		 this, std::placeholders::_1,
																		 std::placeholders::_2);
	this->_validMessageTypes[Engine::Mediator::Message::MOVE] = std::bind(&PlayerGraphicsComponent::handleMove,
																		  this, std::placeholders::_1,
																		  std::placeholders::_2);
}

void Component::PlayerGraphicsComponent::update() noexcept
{
	this->sendToAll(Engine::Mediator::Message::GRAPHICS_REGISTERING);
}

void Component::PlayerGraphicsComponent::handleHit(Engine::Mediator::Message, Engine::AComponent *) noexcept
{
	this->_isHit = true;
}

void Component::PlayerGraphicsComponent::handleDeath(Engine::Mediator::Message, Engine::AComponent *) noexcept
{
	this->_isAlive = false;
}

void Component::PlayerGraphicsComponent::handleMove(Engine::Mediator::Message, Engine::AComponent *sender) noexcept
{
	return;
	if (AMovementComponent *movementComponent = dynamic_cast<AMovementComponent *>(sender)) {
		if (movementComponent->getLastMove().y > 0) {
			this->_currentAnimationId = this->_animationIds[1];
		} else if (movementComponent->getLastMove().y < 0) {
			this->_currentAnimationId = this->_animationIds[3];
		} else {
			if (this->_currentAnimationId == this->_animationIds[1]) {
				this->_currentAnimationId = this->_animationIds[2];
			} else if (this->_currentAnimationId == this->_animationIds[3]) {
				this->_currentAnimationId = this->_animationIds[4];
			} else {
				this->_currentAnimationId = this->_animationIds[0];
			}
		}
	}
}

Engine::AComponent *Component::PlayerGraphicsComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	PlayerGraphicsComponent *newComponent = new PlayerGraphicsComponent(parentEntity, this->_resourceLoader);

	*newComponent = *this;

	return newComponent;
}
