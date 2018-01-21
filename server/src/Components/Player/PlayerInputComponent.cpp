//
// Created by romain on 15/01/18.
//

#include "PlayerInputComponent.hpp"

Component::PlayerInputComponent::PlayerInputComponent(Engine::Entity *parentEntity, Engine::EventList *eventList)
		: AInputComponent(parentEntity), _eventList(eventList)
{
}

void Component::PlayerInputComponent::update() noexcept
{
	this->_event = this->_eventList->getEventById(this->_parentEntity->getId());
	if (this->_event == nullptr) {
		return;
	}

	this->sendToAll(Engine::Mediator::Message::NEW_EVENT);
	this->_event = nullptr;
}

Engine::AComponent *Component::PlayerInputComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	PlayerInputComponent *newComp = new PlayerInputComponent(parentEntity, this->_eventList);

	*newComp = *this;

	return newComp;
}