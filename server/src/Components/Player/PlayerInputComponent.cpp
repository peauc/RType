//
// Created by romain on 15/01/18.
//

#include <Components/Player/PlayerInputComponent.hpp>
#include <iostream>

Component::PlayerInputComponent::PlayerInputComponent(Engine::Entity *parentEntity, Engine::EventList &eventList)
		: AInputComponent(parentEntity), _eventList(eventList)
{
}

void Component::PlayerInputComponent::update()
{
	std::cout << "Updating input" << std::endl;

	this->_event = this->_eventList.getEventById(this->_parentEntity->getId());
	if (this->_event == nullptr) {
		return;
	}

	this->sendToAll(Engine::Mediator::Message::NEW_EVENT);
	this->_event = nullptr;
}


