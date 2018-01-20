//
// Created by romain on 20/01/18.
//

#include <Engine/Entity.hpp>
#include <Components/Camera/CameraZoneComponent.hpp>
#include <iostream>

Component::CameraZoneComponent::CameraZoneComponent(Engine::Entity *parentEntity, Engine::Hitbox hitbox)
		: APhysicsComponent(parentEntity, hitbox)
{
	this->_validMessageTypes[Engine::Mediator::Message::CHECK_COLLISION] = std::bind(
			&CameraZoneComponent::handleCheckCollision,
			this, std::placeholders::_1,
			std::placeholders::_2);
}

void Component::CameraZoneComponent::update()
{
}

void Component::CameraZoneComponent::handleCheckCollision(Engine::Mediator::Message,
														  Engine::AComponent *sender)
{
	if (APhysicsComponent *other = dynamic_cast<APhysicsComponent *>(sender)) {

		this->_orientedBoundingBox = OBB(this->_parentEntity->getTransformComponent(), this->_hitbox);
		other->setOBB();

		this->_orientedBoundingBox.checkIntersection(other->_orientedBoundingBox, *other);
		if (!other->getCollision(TOP) || !other->getCollision(RIGHT) || !other->getCollision(BOTTOM) ||
			!other->getCollision(LEFT)) {
			other->triggerCollision(*this);
		}
	}
}