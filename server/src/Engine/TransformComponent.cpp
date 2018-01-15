//
// Created by romain on 12/01/18.
//

#include <Engine/TransformComponent.hpp>

Engine::TransformComponent::TransformComponent(Entity &parentEntity) : AComponent(parentEntity)
{
}

const Vector2d &Engine::TransformComponent::getPosition() const
{
    return _position;
}

void Engine::TransformComponent::setPosition(const Vector2d &_position)
{
    TransformComponent::_position = _position;
}

const Vector2d &Engine::TransformComponent::getRotation() const
{
    return _rotation;
}

void Engine::TransformComponent::setRotation(const Vector2d &_rotation)
{
    TransformComponent::_rotation = _rotation;
}
