//
// Created by romain on 12/01/18.
//

#include <Components/PlayerMovementComponent.hpp>
#include <Components/AInputComponent.hpp>
#include <Engine/Commands/TransformPositionCommand.hpp>

Component::PlayerMovementComponent::PlayerMovementComponent(Engine::Entity *parentEntity)
		: AMovementComponent(parentEntity),
		  _baseSpeed(1.0f),
		  _lateralBaseSpeed(0.0f),
		  _maxSpeed(2.0f),
		  _lateralMaxSpeed(1.0f),
		  _xInput(0.0f),
		  _yInput(0.0f)
{
	this->_validMessageTypes[Engine::Mediator::Message::NEW_EVENT] = &PlayerMovementComponent::handleEvent;
}

void Component::PlayerMovementComponent::update()
{
	float xMovement = this->_baseSpeed + this->_xInput;
	float yMovement = this->_lateralBaseSpeed + this->_yInput;

	if (xMovement > this->_maxSpeed)
		xMovement = this->_maxSpeed;
	if (yMovement > this->_lateralMaxSpeed)
		yMovement = this->_lateralMaxSpeed;

	this->_parentEntity->addCommand(new Engine::Commands::TransformPositionCommand(this->_parentEntity->getTransformComponent(), xMovement, yMovement));

	this->_xInput = 0;
	this->_yInput = 0;
}

void Component::PlayerMovementComponent::handleEvent(Engine::Mediator::Message messageType, Engine::AComponent *sender)
{
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
