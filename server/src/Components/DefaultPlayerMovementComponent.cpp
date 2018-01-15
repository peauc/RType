//
// Created by romain on 12/01/18.
//

#include <Components/DefaultPlayerMovementComponent.hpp>
#include <Components/AInputComponent.hpp>

Component::DefaultPlayerMovementComponent::DefaultPlayerMovementComponent(Engine::Entity *parentEntity)
        : AMovementComponent(parentEntity),
          _baseSpeed(1.0f),
          _lateralBaseSpeed(0.0f),
          _maxSpeed(2.0f),
          _lateralMaxSpeed(1.0f),
          _xInput(0.0f),
          _yInput(0.0f)
{
}

void Component::DefaultPlayerMovementComponent::update()
{
    float xMovement = this->_baseSpeed + this->_xInput;
    float yMovement = this->_lateralBaseSpeed + this->_yInput;

    if (xMovement > this->_maxSpeed)
        xMovement = this->_maxSpeed;
    if (yMovement > this->_lateralMaxSpeed)
        yMovement = this->_lateralMaxSpeed;
}

void Component::DefaultPlayerMovementComponent::handleEvent(Engine::Message messageType, Engine::AComponent *sender)
{
    if (AInputComponent *inputComponent = dynamic_cast<AInputComponent *>(sender)) {
        this->_xInput = inputComponent->getEvent()._xVelocity;
        this->_yInput = inputComponent->getEvent()._yVelocity;
    }
}
