//
// Created by romain on 12/01/18.
//

#include <Engine/TransformComponent.hpp>

Engine::TransformComponent::TransformComponent(Entity *parentEntity) : AComponent(parentEntity)
{
}

Vector2d &Engine::TransformComponent::getPosition()
{
    return _position;
}

void Engine::TransformComponent::setPosition(Vector2d &_position)
{
    TransformComponent::_position = _position;
}

double Engine::TransformComponent::getRotation()
{
    return _rotation;
}

void Engine::TransformComponent::setRotation(double _rotation)
{
    TransformComponent::_rotation = _rotation;
}

void Engine::TransformComponent::update()
{
}