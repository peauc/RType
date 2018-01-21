//
// Created by romain on 12/01/18.
//

#include "Components/Player/PlayerMovementComponent.hpp"
#include "Components/Abstracts/AInputComponent.hpp"
#include "Engine/Commands/TransformPositionCommand.hpp"
#include "Components/Abstracts/APhysicsComponent.hpp"

Component::PlayerMovementComponent::PlayerMovementComponent(Engine::Entity *parentEntity)
		: AMovementComponent(parentEntity),
		  _baseSpeed(50.0f),
		  _lateralBaseSpeed(0.0f),
		  _maxSpeed(100.0f),
		  _lateralMaxSpeed(50.0f),
		  _xInput(0.0f),
		  _yInput(0.0f)
{
	this->_validMessageTypes[Engine::Mediator::Message::NEW_EVENT] = std::bind(&PlayerMovementComponent::handleEvent,
																			   this, std::placeholders::_1,
																			   std::placeholders::_2);
	this->_validMessageTypes[Engine::Mediator::Message::CAMERA_REPOSITION] = std::bind(
			&PlayerMovementComponent::handleCameraReposition,
			this, std::placeholders::_1,
			std::placeholders::_2);
}

void Component::PlayerMovementComponent::update() noexcept
{
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

void Component::PlayerMovementComponent::handleEvent(Engine::Mediator::Message, Engine::AComponent *sender) noexcept
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

void Component::PlayerMovementComponent::handleCameraReposition(Engine::Mediator::Message,
																Engine::AComponent *sender) noexcept
{
	if (APhysicsComponent *physicsComponent = dynamic_cast<APhysicsComponent *>(sender)) {

		if ((this->_lastMove.y < 0 && !physicsComponent->getCollision(APhysicsComponent::Direction::TOP)) ||
			(this->_lastMove.y > 0 && !physicsComponent->getCollision(APhysicsComponent::Direction::BOTTOM))) {
			this->_parentEntity->getTransformComponent().getPosition().y -= this->_lastMove.y;
			this->_lastMove.y = 0;
		}
		if (this->_lastMove.x > 0 && !physicsComponent->getCollision(APhysicsComponent::Direction::RIGHT)) {
			this->_parentEntity->getTransformComponent().getPosition().x -= this->_lastMove.x;
			this->_lastMove.x = 0;
		}
		if (!physicsComponent->getCollision(APhysicsComponent::Direction::LEFT)) {
			this->_lastMove.x += this->_baseSpeed;
			Engine::Commands::ICommand *command = new Engine::Commands::TransformPositionCommand(
					this->_parentEntity->getTransformComponent(), this->_baseSpeed, 0);
			command->execute();
			this->_parentEntity->addCommand(command);
		}
	}
}

Engine::AComponent *Component::PlayerMovementComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	PlayerMovementComponent *newComp = new PlayerMovementComponent(parentEntity);

	*newComp = *this;

	return newComp;
}
