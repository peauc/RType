//
// Created by romain on 15/01/18.
//

#include <Components/DefaultPlayerInputComponent.hpp>
#include <Components/AMovementComponent.hpp>

Component::DefaultPlayerInputComponent::DefaultPlayerInputComponent(Engine::Entity *parentEntity,
                                                                    std::vector<std::unique_ptr<Engine::Event>> &gameEvents)
        : AInputComponent(parentEntity),
          _gameEvents(gameEvents)
{
}

void Component::DefaultPlayerInputComponent::update()
{
    for (unsigned int i = 0; i < this->_gameEvents.size(); i++) {
        if (this->_gameEvents[i]->_entityId == this->_parentEntity->getId()) {
            this->_event = std::move(this->_gameEvents[i]);
            this->_gameEvents.erase(this->_gameEvents.begin() + i);
            break;
        }
    }
    for (Engine::Mediator mediator : this->_mediators) {
        mediator.send(Engine::Mediator::Message::NEW_EVENT, this);
    }
}


