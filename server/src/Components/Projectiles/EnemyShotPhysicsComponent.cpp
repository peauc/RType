//
// Created by romain on 21/01/18.
//

#include <Components/Projectiles/EnemyShotPhysicsComponent.hpp>

Component::EnemyShotPhysicsComponent::EnemyShotPhysicsComponent(Engine::Entity *parentEntity,
																const Engine::Hitbox &hitbox) :
		APhysicsComponent(parentEntity, hitbox)
{
}

void Component::EnemyShotPhysicsComponent::update() noexcept
{
}
