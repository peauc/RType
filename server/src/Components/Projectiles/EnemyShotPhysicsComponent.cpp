//
// Created by romain on 21/01/18.
//

#include "EnemyShotPhysicsComponent.hpp"

Component::EnemyShotPhysicsComponent::EnemyShotPhysicsComponent(Engine::Entity *parentEntity,
																const Engine::Hitbox &hitbox) :
		APhysicsComponent(parentEntity, hitbox)
{
	this->_collisionHandlers[Engine::Hitbox::Type::PLAYER] = std::bind(&APhysicsComponent::damagingCollision,
																	   this, std::placeholders::_1);
	this->_collisionHandlers[Engine::Hitbox::Type::NEUTRAL] = std::bind(&APhysicsComponent::damagingCollision,
																		this, std::placeholders::_1);
}

void Component::EnemyShotPhysicsComponent::update() noexcept
{
	this->sendToAll(Engine::Mediator::Message::CHECK_COLLISION);
}
