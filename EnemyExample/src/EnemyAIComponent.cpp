//
// Created by buis_p on 1/18/18.
//

#include <iostream>
#include "EnemyAIComponent.hpp"

Component::EnemyAIComponent::EnemyAIComponent(Engine::Entity *parentEntity)
		: AInputComponent(parentEntity) {
}

void Component::EnemyAIComponent::update() noexcept {
	std::cout << "Updating AI" << std::endl;

	std::unique_ptr<Engine::Event>	event(new Engine::Event(0));

	event->_xVelocity = 1;
	event->_yVelocity = 0;
	event->_chargingShot = false;
	event->_shotReleased = false;
	this->_event = move(event);
	if (this->_event == nullptr) {
		return;
	}
	this->sendToAll(Engine::Mediator::Message::NEW_EVENT);
	this->_event = nullptr;
}

Engine::AComponent *Component::EnemyAIComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	EnemyAIComponent *newComp = new EnemyAIComponent(parentEntity);

	*newComp = *this;

	return newComp;
}
