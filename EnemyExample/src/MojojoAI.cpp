//
// Created by buis_p on 1/18/18.
//

#include <iostream>
#include "MojojoAI.hpp"

Component::MojojoAI::MojojoAI(Engine::Entity *parentEntity)
		: AInputComponent(parentEntity) {
	this->i = 0;
}

void Component::MojojoAI::update() noexcept {
	std::unique_ptr<Engine::Event>	event(new Engine::Event(0));

	event->_xVelocity = 1;
	if (this->i >= 25)
		event->_yVelocity = 1;
	else if (this->i >= 50)
		event->_yVelocity = -1;
	else
		event->_yVelocity = 0;
	event->_chargingShot = false;
	if (this->i >= 100) {
		event->_shotReleased = false;
		this->i = 0;
	}
	this->_event = move(event);
	if (this->_event == nullptr) {
		return;
	}
	this->sendToAll(Engine::Mediator::Message::NEW_EVENT);
	this->_event = nullptr;
	++i;
}

Engine::AComponent *Component::MojojoAI::clone(Engine::Entity *parentEntity) const noexcept
{
	MojojoAI *newComp = new MojojoAI(parentEntity);

	*newComp = *this;

	return newComp;
}
