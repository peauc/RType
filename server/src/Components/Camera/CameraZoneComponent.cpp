//
// Created by romain on 20/01/18.
//

#include <iostream>
#include "Entity.hpp"
#include "CameraZoneComponent.hpp"

Component::CameraZoneComponent::CameraZoneComponent(Engine::Entity *parentEntity, Engine::Hitbox hitbox)
		: APhysicsComponent(parentEntity, hitbox)
{
	this->_validMessageTypes[Engine::Mediator::Message::CHECK_COLLISION] = std::bind(
			&CameraZoneComponent::handleCheckCollision,
			this, std::placeholders::_1,
			std::placeholders::_2);
}

void Component::CameraZoneComponent::update() noexcept
{
}

void Component::CameraZoneComponent::handleCheckCollision(Engine::Mediator::Message,
														  Engine::AComponent *sender) noexcept
{
	if (APhysicsComponent *other = dynamic_cast<APhysicsComponent *>(sender)) {

		this->setOBB();
		other->setOBB();

		this->_orientedBoundingBox->checkIntersection(*other);
		if (!other->getCollision(TOP) || !other->getCollision(RIGHT) || !other->getCollision(BOTTOM) ||
			!other->getCollision(LEFT)) {
			other->triggerCollision(*this);
		}
	}
}