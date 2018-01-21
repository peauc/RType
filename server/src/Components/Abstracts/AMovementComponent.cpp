//
// Created by romain on 15/01/18.
//

#include <Components/Abstracts/AInputComponent.hpp>
#include <Components/Abstracts/AMovementComponent.hpp>
#include <Components/Abstracts/APhysicsComponent.hpp>
#include <iostream>

Component::AMovementComponent::AMovementComponent(Engine::Entity *parentEntity) : AComponent(parentEntity)
{
	this->_validMessageTypes[Engine::Mediator::Message::CANCEL_MOVE] = std::bind(&AMovementComponent::handleCancelMove,
																				 this, std::placeholders::_1,
																				 std::placeholders::_2);
}

void Component::AMovementComponent::handleCancelMove(Engine::Mediator::Message, Engine::AComponent *sender)
{
	if (APhysicsComponent *physicsComponent = dynamic_cast<APhysicsComponent *>(sender)) {
		if ((this->_lastMove.x > 0 && physicsComponent->getCollision(APhysicsComponent::Direction::RIGHT)) ||
			(this->_lastMove.x < 0 && physicsComponent->getCollision(APhysicsComponent::Direction::LEFT))) {
			this->_parentEntity->getTransformComponent().getPosition().x -= this->_lastMove.x;
			this->_lastMove.x = 0;
		}
		if ((this->_lastMove.y > 0 && physicsComponent->getCollision(APhysicsComponent::Direction::BOTTOM)) ||
			(this->_lastMove.y < 0 && physicsComponent->getCollision(APhysicsComponent::Direction::TOP))) {
			this->_parentEntity->getTransformComponent().getPosition().y -= this->_lastMove.y;
			this->_lastMove.y = 0;
		}
	}
}

Component::AMovementComponent &Component::AMovementComponent::operator=(const Component::AMovementComponent &)
{
	this->_event = nullptr;

	return *this;
}

const Vector2d &Component::AMovementComponent::getLastMove() const
{
	return _lastMove;
}
