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
	std::cout << "Cancel move" << std::endl;
	if (APhysicsComponent *physicsComponent = dynamic_cast<APhysicsComponent *>(sender)) {
		std::cout << "TOP : " << physicsComponent->getCollision(Component::APhysicsComponent::TOP) << std::endl;
		std::cout << "RIGHT : " << physicsComponent->getCollision(Component::APhysicsComponent::RIGHT) << std::endl;
		std::cout << "BOTTOM : " << physicsComponent->getCollision(Component::APhysicsComponent::BOTTOM) << std::endl;
		std::cout << "LEFT : " << physicsComponent->getCollision(Component::APhysicsComponent::LEFT) << std::endl;
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
