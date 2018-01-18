//
// Created by romain on 17/01/18.
//

#include <Components/PlayerPhysicsComponent.hpp>
#include <iostream>

Component::PlayerPhysicsComponent::PlayerPhysicsComponent(Engine::Entity *entity) : APhysicsComponent(entity)
{
}

void Component::PlayerPhysicsComponent::update()
{
	std::cout << "Updating physics" << std::endl;
}

void Component::PlayerPhysicsComponent::triggerCollision(Component::APhysicsComponent &other)
{
}