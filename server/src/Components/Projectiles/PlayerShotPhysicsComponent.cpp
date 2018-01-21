//
// Created by romain on 21/01/18.
//

#include "Engine/Entity.hpp"
#include "Engine/Hitbox.hpp"
#include "Components/Abstracts/APhysicsComponent.hpp"
#include "Components/Projectiles/PlayerShotPhysicsComponent.hpp"

Component::PlayerShotPhysicsComponent::PlayerShotPhysicsComponent(Engine::Entity *parentEntity,
																  const Engine::Hitbox &hitbox)
		: APhysicsComponent(parentEntity, hitbox)
{
	this->_collisionHandlers[Engine::Hitbox::Type::ENEMY] = std::bind(&APhysicsComponent::damagingCollision,
																	  this, std::placeholders::_1);
	this->_collisionHandlers[Engine::Hitbox::Type::NEUTRAL] = std::bind(&APhysicsComponent::damagingCollision,
																		this, std::placeholders::_1);
}

void Component::PlayerShotPhysicsComponent::update() noexcept
{
	this->sendToAll(Engine::Mediator::Message::CHECK_COLLISION);
}
