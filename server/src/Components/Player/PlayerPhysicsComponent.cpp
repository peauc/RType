//
// Created by romain on 19/01/18.
//

#include <iostream>
#include "Entity.hpp"
#include "Hitbox.hpp"
#include "APhysicsComponent.hpp"
#include "PlayerPhysicsComponent.hpp"

Component::PlayerPhysicsComponent::PlayerPhysicsComponent(Engine::Entity *parentEntity, Engine::Hitbox hitbox)
		: APhysicsComponent(parentEntity, hitbox)
{
	this->_collisionHandlers[Engine::Hitbox::Type::CAMERA] = std::bind(&PlayerPhysicsComponent::cameraCollision,
																	   this, std::placeholders::_1);
	this->_collisionHandlers[Engine::Hitbox::Type::ENEMY] = std::bind(&APhysicsComponent::damagingCollision,
																	  this, std::placeholders::_1);
	this->_collisionHandlers[Engine::Hitbox::Type::ENEMY_SHOT] = std::bind(&APhysicsComponent::damagingCollision,
																		   this, std::placeholders::_1);
	this->_collisionHandlers[Engine::Hitbox::Type::NEUTRAL] = std::bind(&APhysicsComponent::damagingCollision,
																		this, std::placeholders::_1);
}

void Component::PlayerPhysicsComponent::update() noexcept
{
	this->sendToAll(Engine::Mediator::Message::CHECK_COLLISION);
}

void Component::PlayerPhysicsComponent::cameraCollision(APhysicsComponent &) noexcept
{
	this->sendToAll(Engine::Mediator::CAMERA_REPOSITION);
}

Engine::AComponent *Component::PlayerPhysicsComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	PlayerPhysicsComponent *newComp = new PlayerPhysicsComponent(parentEntity, this->_hitbox);

	*newComp = *this;

	return newComp;
}