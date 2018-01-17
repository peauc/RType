//
// Created by romain on 16/01/18.
//

#include <Components/DefaultCameraMovementComponent.hpp>
#include <Engine/Commands/TransformPositionCommand.hpp>

Component::DefaultCameraMovementComponent::DefaultCameraMovementComponent(Engine::Entity *parentEntity,
																		  Engine::Game *parentGame)
		: AMovementComponent(parentEntity), _parentGame(parentGame)
{
}

void Component::DefaultCameraMovementComponent::update()
{
	this->_parentEntity->addCommand(new Engine::Commands::TransformPositionCommand(this->_parentEntity->getTransformComponent(), 0.1f, 0.0f));
}