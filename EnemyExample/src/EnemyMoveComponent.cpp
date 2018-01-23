//
// Created by buis_p on 1/18/18.
//

#include <iostream>
#include "EnemyMoveComponent.hpp"
#include "AInputComponent.hpp"
#include "TransformPositionCommand.hpp"

Component::EnemyMoveComponent::EnemyMoveComponent(Engine::Entity *parentEntity)
		: AMovementComponent(parentEntity),
		  _baseSpeed(1.0f),
		  _lateralBaseSpeed(0.0f),
		  _maxSpeed(2.0f),
		  _lateralMaxSpeed(1.0f),
		  _xInput(0.0f),
		  _yInput(0.0f)
{
	this->_validMessageTypes[Engine::Mediator::Message::NEW_EVENT] = std::bind(&EnemyMoveComponent::handleEvent,
																			   this, std::placeholders::_1,
																			   std::placeholders::_2);
}

void Component::EnemyMoveComponent::update() noexcept {
	std::cout << "Updating movement" << std::endl;
	this->_lastMove.x = this->_baseSpeed + this->_xInput * this->_baseSpeed;
	this->_lastMove.y = this->_lateralBaseSpeed + this->_yInput * this->_lateralMaxSpeed;

	if (this->_lastMove.x > this->_maxSpeed)
		this->_lastMove.x = this->_maxSpeed;
	if (this->_lastMove.y > this->_lateralMaxSpeed)
		this->_lastMove.y = this->_lateralMaxSpeed;

	Engine::Commands::ICommand *command = new Engine::Commands::TransformPositionCommand(
			this->_parentEntity->getTransformComponent(), this->_lastMove.x, this->_lastMove.y);
	command->execute();

	this->sendToAll(Engine::Mediator::Message::MOVE);

	this->_xInput = 0;
	this->_yInput = 0;
}

void Component::EnemyMoveComponent::handleEvent(Engine::Mediator::Message messageType, Engine::AComponent *sender)
{
	std::cout << "Handling event" << std::endl;
	if (AInputComponent *inputComponent = dynamic_cast<AInputComponent *>(sender)) {
		if (inputComponent->hasEvent()) {
			this->_xInput = inputComponent->getEvent()._xVelocity;
			this->_yInput = inputComponent->getEvent()._yVelocity;
		} else {
			this->_xInput = 0;
			this->_yInput = 0;
		}
	}
}

Engine::AComponent *Component::EnemyMoveComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	EnemyMoveComponent *newComp = new EnemyMoveComponent(parentEntity);

	*newComp = *this;

	return newComp;
}
