//
// Created by romain on 16/01/18.
//

#include <Components/Camera/CameraMovementComponent.hpp>
#include <Engine/Commands/TransformPositionCommand.hpp>

Component::CameraMovementComponent::CameraMovementComponent(Engine::Entity *parentEntity,
																		  Engine::Game *parentGame)
		: AMovementComponent(parentEntity), _parentGame(parentGame)
{
}

void Component::CameraMovementComponent::update() noexcept
{
	this->_parentEntity->getTransformComponent().getPosition().x += 50.0f;
	this->_parentEntity->getTransformComponent().getPosition().y += 0.0f;
}