//
// Created by romain on 21/01/18.
//

#include "Components/Zone/ZoneComponent.hpp"

Component::ZoneComponent::ZoneComponent(Engine::Entity *parentEntity,
										const Engine::Hitbox &hitbox,
										Engine::World *parentWorld) :
		APhysicsComponent(parentEntity, hitbox), _parentWorld(parentWorld)
{
	this->setOBB();
	this->_validMessageTypes[Engine::Mediator::Message::CHECK_COLLISION] = std::bind(
			&ZoneComponent::handleCheckCollision,
			this, std::placeholders::_1,
			std::placeholders::_2);
}

void Component::ZoneComponent::update() noexcept
{
}

void Component::ZoneComponent::handleCheckCollision(Engine::Mediator::Message, Engine::AComponent *sender) noexcept
{
	if (APhysicsComponent *other = dynamic_cast<APhysicsComponent *>(sender)) {
		other->setOBB();

		if (this->_orientedBoundingBox->checkIntersection(*other) ||
			other->_orientedBoundingBox->checkIntersection(*this)) {
			this->trigger();
		}
	}
}

void Component::ZoneComponent::addEntity(std::unique_ptr<Engine::Entity> entity) noexcept
{
	this->_entities.push_back(std::move(entity));
}

void Component::ZoneComponent::trigger() noexcept
{
	for (auto &entity : this->_entities) {
		entity->setActive(true);
		this->_parentWorld->addObject(std::move(entity));
	}
	this->_parentEntity->setActive(false);
}