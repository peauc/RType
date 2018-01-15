//
// Created by romain on 12/01/18.
//

#include <Engine/AComponent.hpp>

Engine::AComponent::AComponent(Engine::Entity &parentEntity) : _parentEntity(parentEntity)
{
}

void Engine::AComponent::registerToMediator(Engine::Mediator &mediator)
{
    this->_mediators.push_back(mediator);
    mediator.registerComponent(*this);
}

void Engine::AComponent::unregisterToMediator(Engine::Mediator &mediator)
{
    this->_mediators.erase(std::find(this->_mediators.begin(), this->_mediators.end(), mediator));
    mediator.unregisterComponent(*this);
}

void Engine::AComponent::receive(Engine::Message messageType, Engine::AComponent *sender)
{
    this->_validMessageTypes[messageType](messageType, sender);
}
