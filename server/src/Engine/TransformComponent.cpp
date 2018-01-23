//
// Created by romain on 12/01/18.
//

#include "TransformComponent.hpp"

Engine::TransformComponent::TransformComponent(Entity *parentEntity) : AComponent(parentEntity), _position(0, 0), _rotation(0), _rotationRadians(0)
{
}

Vector2d &Engine::TransformComponent::getPosition() noexcept
{
	return _position;
}

const Vector2d &Engine::TransformComponent::getPosition() const noexcept
{
	return _position;
}

void Engine::TransformComponent::setPosition(Vector2d &_position) noexcept
{
	TransformComponent::_position = _position;
}

double Engine::TransformComponent::getRotation() const noexcept
{
	return _rotation;
}

double Engine::TransformComponent::getRotationRadians() const noexcept
{
	return this->_rotationRadians;
}

void Engine::TransformComponent::setRotation(double _rotation) noexcept
{
	TransformComponent::_rotation = _rotation;
	this->_rotationRadians = this->_rotation * M_PI / 180;
}

void Engine::TransformComponent::update() noexcept
{
}
