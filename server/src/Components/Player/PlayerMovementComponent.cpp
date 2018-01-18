//
// Created by romain on 12/01/18.
//

#include <Components/Player/PlayerMovementComponent.hpp>
#include <Components/Abstracts/AInputComponent.hpp>
#include <Engine/Commands/TransformPositionCommand.hpp>
#include <iostream>

Component::PlayerMovementComponent::PlayerMovementComponent(Engine::Entity *parentEntity)
		: AMovementComponent(parentEntity),
		  _baseSpeed(1.0f),
		  _lateralBaseSpeed(0.0f),
		  _maxSpeed(2.0f),
		  _lateralMaxSpeed(1.0f),
		  _xInput(0.0f),
		  _yInput(0.0f)
{
	this->_validMessageTypes[Engine::Mediator::Message::NEW_EVENT] = std::bind(&PlayerMovementComponent::handleEvent,
																			   this, std::placeholders::_1,
																			   std::placeholders::_2);
}

void Component::PlayerMovementComponent::update()
{
	std::cout << "Updating movement" << std::endl;
	float xMovement = this->_baseSpeed + this->_xInput;
	float yMovement = this->_lateralBaseSpeed + this->_yInput;

	if (xMovement > this->_maxSpeed)
		xMovement = this->_maxSpeed;
	if (yMovement > this->_lateralMaxSpeed)
		yMovement = this->_lateralMaxSpeed;

	Engine::Commands::ICommand *command= new Engine::Commands::TransformPositionCommand(this->_parentEntity->getTransformComponent(), xMovement, yMovement);
	command->execute();
	this->_parentEntity->addCommand(command);

	this->_xInput = 0;
	this->_yInput = 0;
}

void Component::PlayerMovementComponent::handleEvent(Engine::Mediator::Message messageType, Engine::AComponent *sender)
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
