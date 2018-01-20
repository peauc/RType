//
// Created by romain on 12/01/18.
//

#include <Engine/TransformComponent.hpp>

Engine::TransformComponent::TransformComponent(Entity *parentEntity) : AComponent(parentEntity), _position(0, 0)
{
}

Vector2d &Engine::TransformComponent::getPosition()
{
	return _position;
}

const Vector2d &Engine::TransformComponent::getPosition() const
{
	return _position;
}

void Engine::TransformComponent::setPosition(Vector2d &_position)
{
	TransformComponent::_position = _position;
}

const double Engine::TransformComponent::getRotation() const
{
	return _rotation;
}

const double Engine::TransformComponent::getRotationRadians() const
{
	return this->_rotationRadians;
}

void Engine::TransformComponent::setRotation(double _rotation)
{
	TransformComponent::_rotation = _rotation;
	this->_rotationRadians = this->_rotation * M_PI / 180;
}

void Engine::TransformComponent::update()
{
}
