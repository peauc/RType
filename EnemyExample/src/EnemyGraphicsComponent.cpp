//
// Created by buis_p on 1/18/18.
//


#include <iostream>
#include "EnemyGraphicsComponent.hpp"
#include "AMovementComponent.hpp"

Component::EnemyGraphicsComponent::EnemyGraphicsComponent(Engine::Entity *parentEntity,
															ResourcesLoader *resourceLoader) :
		AGraphicsComponent(parentEntity, resourceLoader) {
	this->_animationIds.push_back(1);
	this->_animationIds.push_back(0);
	this->_currentAnimationId = this->_animationIds[0];

	this->_relativeStartPos.x = -500;
	this->_relativeStartPos.y = -300;
	this->_relativeRange.x = 1000;
	this->_relativeRange.y = 600;

	if (this->setHitbox()) {
		std::cerr << "Missing ressource" << std::endl;
	}
	this->_validMessageTypes[Engine::Mediator::Message::DEATH] = std::bind(&EnemyGraphicsComponent::handleDeath,
																		   this, std::placeholders::_1,
																		   std::placeholders::_2);
	this->_validMessageTypes[Engine::Mediator::Message::HIT] = std::bind(&EnemyGraphicsComponent::handleHit,
																		 this, std::placeholders::_1,
																		 std::placeholders::_2);
}

void Component::EnemyGraphicsComponent::update() {
	this->sendToAll(Engine::Mediator::Message::GRAPHICS_REGISTERING);
}

void Component::EnemyGraphicsComponent::handleHit(Engine::Mediator::Message, Engine::AComponent *) noexcept {
	this->_isHit = true;
}

void Component::EnemyGraphicsComponent::handleDeath(Engine::Mediator::Message, Engine::AComponent *) noexcept {
	this->_currentAnimationId = this->_animationIds[1];
	this->_isAlive = false;
}

void Component::EnemyGraphicsComponent::handleMove(Engine::Mediator::Message, Engine::AComponent *sender) noexcept {
	if (AMovementComponent *movementComponent = dynamic_cast<AMovementComponent *>(sender)) {
		if (movementComponent->getLastMove().y > 0) {
			this->_currentAnimationId = this->_animationIds[0];
		} else if (movementComponent->getLastMove().y < 0) {
			this->_currentAnimationId = this->_animationIds[0];
		} else
			this->_currentAnimationId = this->_animationIds[0];
	}
}

Engine::AComponent *Component::EnemyGraphicsComponent::clone(Engine::Entity *parentEntity) const noexcept {
	EnemyGraphicsComponent *newComponent = new EnemyGraphicsComponent(parentEntity, this->_resourceLoader);

	*newComponent = *this;

	return newComponent;
}
