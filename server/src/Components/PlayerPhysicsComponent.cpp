//
// Created by romain on 17/01/18.
//

#include <Components/PlayerPhysicsComponent.hpp>

Component::PlayerPhysicsComponent::PlayerPhysicsComponent(Engine::Entity *entity) : APhysicsComponent(entity)
{
}

void Component::PlayerPhysicsComponent::update()
{
}

void Component::PlayerPhysicsComponent::triggerCollision(Component::APhysicsComponent &other)
{
}