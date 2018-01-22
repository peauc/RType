//
// Created by romain on 15/01/18.
//

#include <iostream>
#include "PlayerInputComponent.hpp"

Component::PlayerInputComponent::PlayerInputComponent(Engine::Entity *parentEntity, Engine::EventList *eventList)
		: AInputComponent(parentEntity), _eventList(eventList)
{
}

void Component::PlayerInputComponent::update() noexcept
{
	std::cout << "---------------------------------------------" << 
								     std::endl << this->_parentEntity->getId() << std::endl;
	this->_event = this->_eventList->getEventById(this->_parentEntity->getId());
	if (this->_event == nullptr) {
		return;
	}
	std::cout << "Player :" << this->_event->_yVelocity << " " << 
						      this->_event->_xVelocity << std::endl;
	
	
	this->sendToAll(Engine::Mediator::Message::NEW_EVENT);
	this->_event = nullptr;
}

Engine::AComponent *Component::PlayerInputComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	PlayerInputComponent *newComp = new PlayerInputComponent(parentEntity, this->_eventList);

	*newComp = *this;

	return newComp;
}