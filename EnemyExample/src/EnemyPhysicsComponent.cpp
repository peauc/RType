//
// Created by buis_p on 1/18/18.
//


#include <iostream>
#include "Engine/Entity.hpp"
#include "Engine/Hitbox.hpp"
#include "Components/Abstracts/APhysicsComponent.hpp"
#include "EnemyPhysicsComponent.hpp"

Component::EnemyPhysicsComponent::EnemyPhysicsComponent(Engine::Entity *parentEntity, Engine::Hitbox hitbox)
		: APhysicsComponent(parentEntity, hitbox)
{
	this->_collisionHandlers[Engine::Hitbox::Type::CAMERA] = std::bind(&EnemyPhysicsComponent::cameraCollision,
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

void Component::EnemyPhysicsComponent::update()
{
	this->sendToAll(Engine::Mediator::Message::CHECK_COLLISION);
}

void Component::EnemyPhysicsComponent::cameraCollision(APhysicsComponent &)
{
	std::cout << "Camera collision" << std::endl;
}

