//
// Created by romain on 15/01/18.
//

#include <Components/DefaultPlayerInputComponent.hpp>
#include <Components/AMovementComponent.hpp>

Component::DefaultPlayerInputComponent::DefaultPlayerInputComponent(Engine::Entity &parentEntity,
                                                                    std::vector<std::unique_ptr<Engine::Event>> &gameEvents)
        : AInputComponent(parentEntity),
          _gameEvents(gameEvents)
{
}

void Component::DefaultPlayerInputComponent::update()
{
    for (std::vector<std::unique_ptr<Engine::Event>>::const_iterator it = this->_gameEvents.begin();
         it != this->_gameEvents.end(); it++) {
        if ((*it)->_entityId == this->_parentEntity.getId()) {
            this->_event = std::unique_ptr(it->release());
            this->_gameEvents.erase(it);
            break;
        }
    }
    for (Engine::Mediator mediator : this->_mediators) {
        mediator.send(Engine::Message::NEW_EVENT, *this);
    }
}

const Engine::Event &Component::DefaultPlayerInputComponent::getEvent() const
{
    return *_event;
}


