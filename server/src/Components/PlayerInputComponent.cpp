//
// Created by romain on 15/01/18.
//

#include <Components/PlayerInputComponent.hpp>
#include <iostream>

Component::PlayerInputComponent::PlayerInputComponent(Engine::Entity *parentEntity,
																	std::vector<std::unique_ptr<Engine::Event>> &gameEvents)
		: AInputComponent(parentEntity),
		  _gameEvents(gameEvents)
{
}

void Component::PlayerInputComponent::update()
{
	std::cout << "Updating input" << std::endl;
	for (unsigned int i = 0; i < this->_gameEvents.size(); i++) {
		if (this->_gameEvents[i]->_entityId == this->_parentEntity->getId()) {
			this->_event = std::move(this->_gameEvents[i]);
			this->_gameEvents.erase(this->_gameEvents.begin() + i);
			break;
		}
	}
	this->sendToAll(Engine::Mediator::Message::NEW_EVENT);
	this->_event = nullptr;
}


