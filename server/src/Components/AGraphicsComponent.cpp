//
// Created by romain on 16/01/18.
//

#include <Components/AGraphicsComponent.hpp>

Component::AGraphicsComponent::AGraphicsComponent(Engine::Entity *parentEntity, Engine::Game *parentGame) :
		AComponent(parentEntity), _parentGame(parentGame)
{
}

Component::AGraphicsComponent::~AGraphicsComponent()
{
}