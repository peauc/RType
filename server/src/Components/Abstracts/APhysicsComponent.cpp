//
// Created by romain on 17/01/18.
//

#include "APhysicsComponent.hpp"
#include "Entity.hpp"

Component::APhysicsComponent::APhysicsComponent(Engine::Entity *entity, const Engine::Hitbox &hitbox) :
		AComponent(entity), _hitbox(hitbox)
{
	this->_validMessageTypes[Engine::Mediator::Message::CHECK_COLLISION] = std::bind(
			&APhysicsComponent::handleCheckCollision,
			this, std::placeholders::_1,
			std::placeholders::_2);
}

int Component::APhysicsComponent::getCollisionDamages() const noexcept
{
	return _collisionDamages;
}

void Component::APhysicsComponent::setCollisionDamages(int collisionDamages) noexcept
{
	this->_collisionDamages = collisionDamages;
}

void Component::APhysicsComponent::handleCheckCollision(Engine::Mediator::Message,
														Engine::AComponent *sender) noexcept
{
	if (APhysicsComponent *other = dynamic_cast<APhysicsComponent *>(sender)) {
		this->setOBB();
		this->setOBB();

		if (this->_orientedBoundingBox->checkIntersection(*other) ||
			other->_orientedBoundingBox->checkIntersection(*this)) {
			this->_collisionDamages = 0;
			if (!this->_mediators.empty()) {
				this->_mediators[0]->send(Engine::Mediator::Message::GET_IMPACT_DAMAGES, this);
			}
			other->triggerCollision(*this);
			this->triggerCollision(*other);
			this->_collisionDamages = 0;
			this->resetCollisions();
			other->resetCollisions();
		}
	}
}

void Component::APhysicsComponent::handleMove(Engine::Mediator::Message, Engine::AComponent *) noexcept
{
	this->_orientedBoundingBox = nullptr;
}

void Component::APhysicsComponent::triggerCollision(Component::APhysicsComponent &other) noexcept
{
	if (this->_collisionDamages == 0) {
		if (!this->_mediators.empty()) {
			this->_mediators[0]->send(Engine::Mediator::Message::GET_IMPACT_DAMAGES, this);
		}
	}
	if (this->_collisionHandlers.count(other._hitbox._type) != 0) {
		this->_collisionHandlers[other._hitbox._type](other);
	}
}

void Component::APhysicsComponent::blockingCollision(Component::APhysicsComponent &) noexcept
{
	if (!this->_mediators.empty()) {
		this->_mediators[0]->send(Engine::Mediator::Message::CANCEL_MOVE, this);
	}
}

void Component::APhysicsComponent::damagingCollision(Component::APhysicsComponent &) noexcept
{
	if (!this->_mediators.empty()) {
		this->_mediators[0]->send(Engine::Mediator::Message::HIT, this);
	}
}

void Component::APhysicsComponent::setCollision(Component::APhysicsComponent::Direction direction, bool hasHappened) noexcept
{
	this->_collisions[direction] = hasHappened;
}

void Component::APhysicsComponent::resetCollisions() noexcept
{
	for (bool &_collision : this->_collisions) {
		_collision = false;
	}
}

bool Component::APhysicsComponent::getCollision(Component::APhysicsComponent::Direction direction) const noexcept
{
	return this->_collisions[direction];
}

void Component::APhysicsComponent::setOBB() noexcept
{
	if (this->_orientedBoundingBox == nullptr)
		this->_orientedBoundingBox = std::make_unique<OBB>(this->_parentEntity->getTransformComponent(), this->_hitbox);
}

Component::APhysicsComponent &Component::APhysicsComponent::operator=(const Component::APhysicsComponent &other) noexcept
{
	this->_collisionHandlers = other._collisionHandlers;

	return *this;
}

Component::APhysicsComponent::OBB::OBB(const Engine::TransformComponent &transformComponent,
									   const Engine::Hitbox &hitbox)
{
	this->center = transformComponent.getPosition();

	double tempX;
	double tempY;

	tempX = hitbox._relativeStartPos.x;
	tempY = hitbox._relativeStartPos.y;
	this->p1.x = tempX * cos(transformComponent.getRotationRadians()) -
				 tempY * sin(transformComponent.getRotationRadians()) +
				 this->center.x;
	this->p1.y = tempX * sin(transformComponent.getRotationRadians()) +
				 tempY * cos(transformComponent.getRotationRadians()) +
				 this->center.y;

	tempX = hitbox._relativeStartPos.x + hitbox._relativeRange.x;
	this->p2.x = tempX * cos(transformComponent.getRotationRadians()) -
				 tempY * sin(transformComponent.getRotationRadians()) +
				 this->center.x;
	this->p2.y = tempX * sin(transformComponent.getRotationRadians()) +
				 tempY * cos(transformComponent.getRotationRadians()) +
				 this->center.y;

	tempY = hitbox._relativeStartPos.y + hitbox._relativeRange.y;
	this->p3.x = tempX * cos(transformComponent.getRotationRadians()) -
				 tempY * sin(transformComponent.getRotationRadians()) +
				 this->center.x;
	this->p3.y = tempX * sin(transformComponent.getRotationRadians()) +
				 tempY * cos(transformComponent.getRotationRadians()) +
				 this->center.y;

	tempX = hitbox._relativeStartPos.x;
	this->p4.x = tempX * cos(transformComponent.getRotationRadians()) -
				 tempY * sin(transformComponent.getRotationRadians()) +
				 this->center.x;
	this->p4.y = tempX * sin(transformComponent.getRotationRadians()) +
				 tempY * cos(transformComponent.getRotationRadians()) +
				 this->center.y;
}

bool Component::APhysicsComponent::OBB::checkIntersection(APhysicsComponent &physics) noexcept
{
	bool c1, c2, c3, c4;
	c1 = this->checkIntersection(physics._orientedBoundingBox->p1);
	c2 = this->checkIntersection(physics._orientedBoundingBox->p2);
	c3 = this->checkIntersection(physics._orientedBoundingBox->p3);
	c4 = this->checkIntersection(physics._orientedBoundingBox->p4);

	physics.setCollision(Direction::TOP, (c1 && c2) || (c2 && !c3) || (c1 && !c4));
	physics.setCollision(Direction::RIGHT, (c2 && c3) || (c2 && !c1) || (c3 && !c4));
	physics.setCollision(Direction::BOTTOM, (c3 && c4) || (c4 && !c1) || (c3 && !c2));
	physics.setCollision(Direction::LEFT, (c4 && c1) || (c1 && !c2) || (c4 && !c3));

	return (c1 || c2 || c3 || c4);
}

bool Component::APhysicsComponent::OBB::checkIntersection(const Vector2d &point) noexcept
{
	return (this->p2.x - this->p1.x) * (point.y - this->p1.y) - (this->p2.y - this->p1.y) * (point.x - this->p1.x) >=
		   0 &&
		   (this->p3.x - this->p2.x) * (point.y - this->p2.y) - (this->p3.y - this->p2.y) * (point.x - this->p2.x) >=
		   0 &&
		   (this->p4.x - this->p3.x) * (point.y - this->p3.y) - (this->p4.y - this->p3.y) * (point.x - this->p3.x) >=
		   0 &&
		   (this->p1.x - this->p4.x) * (point.y - this->p4.y) - (this->p1.y - this->p4.y) * (point.x - this->p4.x) >= 0;
}