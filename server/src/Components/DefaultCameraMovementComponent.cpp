//
// Created by romain on 14/01/18.
//

#include <Components/DefaultCameraMovementComponent.hpp>

Components::DefaultCameraMovementComponent::DefaultCameraMovementComponent(Engine::Entity &parentEntity) : AComponent(
        parentEntity)
{
    this->_speed = 1.0f;
}

void Components::DefaultCameraMovementComponent::update()
{
    this->_parentEntity.getTransformComponent().getPosition().x += this->_speed;
}
