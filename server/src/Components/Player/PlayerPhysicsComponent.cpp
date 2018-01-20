//
// Created by romain on 19/01/18.
//

#include <Engine/Entity.hpp>
#include <Engine/Hitbox.hpp>
#include <Components/Abstracts/APhysicsComponent.hpp>
#include <Components/Player/PlayerPhysicsComponent.hpp>
#include <iostream>

Component::PlayerPhysicsComponent::PlayerPhysicsComponent(Engine::Entity *parentEntity, Engine::Hitbox hitbox)
		: APhysicsComponent(parentEntity, hitbox)
{
	this->_collisionHandlers[Engine::Hitbox::Type::CAMERA] = std::bind(&PlayerPhysicsComponent::cameraCollision,
																	   this, std::placeholders::_1);
	this->_collisionHandlers[Engine::Hitbox::Type::PLAYER] = std::bind(&APhysicsComponent::blockingCollision,
																	   this, std::placeholders::_1);
	this->_collisionHandlers[Engine::Hitbox::Type::ENEMY] = std::bind(&APhysicsComponent::damagingCollision,
																	  this, std::placeholders::_1);
	this->_collisionHandlers[Engine::Hitbox::Type::ENEMY_SHOT] = std::bind(&APhysicsComponent::damagingCollision,
																		   this, std::placeholders::_1);
	this->_collisionHandlers[Engine::Hitbox::Type::NEUTRAL] = std::bind(&APhysicsComponent::damagingCollision,
																		this, std::placeholders::_1);
}

void Component::PlayerPhysicsComponent::update()
{
	std::cout << "updating physics" << std::endl;
	this->sendToAll(Engine::Mediator::Message::CHECK_COLLISION);
}

void Component::PlayerPhysicsComponent::cameraCollision(APhysicsComponent &)
{
	std::cout << "Camera collision" << std::endl;
}

