//
// Created by romain on 17/01/18.
//

#include <Components/Abstracts/APhysicsComponent.hpp>
#include <iostream>

Component::APhysicsComponent::APhysicsComponent(Engine::Entity *entity, Engine::Hitbox hitbox) : AComponent(entity),
																								 _hitbox(hitbox)
{
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

bool Component::APhysicsComponent::OBB::checkIntersection(const Component::APhysicsComponent::OBB &other)
{
	return this->checkIntersection(other.p1) || this->checkIntersection(other.p2) ||
		   this->checkIntersection(other.p3) || this->checkIntersection(other.p4);
}

bool Component::APhysicsComponent::OBB::checkIntersection(const Vector2d &point)
{
	return (this->p2.x - this->p1.x) * (point.y - this->p1.y) - (this->p2.y - this->p1.y) * (point.x - this->p1.x) >=
		   0 &&
		   (this->p3.x - this->p2.x) * (point.y - this->p2.y) - (this->p3.y - this->p2.y) * (point.x - this->p2.x) >=
		   0 &&
		   (this->p4.x - this->p3.x) * (point.y - this->p3.y) - (this->p4.y - this->p3.y) * (point.x - this->p3.x) >=
		   0 &&
		   (this->p1.x - this->p4.x) * (point.y - this->p4.y) - (this->p1.y - this->p4.y) * (point.x - this->p4.x) >= 0;
}
