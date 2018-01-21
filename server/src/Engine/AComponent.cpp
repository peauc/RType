//
// Created by romain on 12/01/18.
//

#include <Engine/AComponent.hpp>
#include <Engine/Entity.hpp>
#include <iostream>

Engine::AComponent::AComponent(Engine::Entity *parentEntity) : _parentEntity(parentEntity)
{
}

void Engine::AComponent::registerToMediator(Engine::Mediator *mediator)
{
	this->_mediators.push_back(mediator);
	mediator->registerComponent(this);
}

void Engine::AComponent::unregisterToMediator(Engine::Mediator *mediator)
{
	this->_mediators.erase(std::find(this->_mediators.begin(), this->_mediators.end(), mediator));
	mediator->unregisterComponent(this);
}

void Engine::AComponent::receive(Engine::Mediator::Message messageType, Engine::AComponent *sender)
{
	if (this->_validMessageTypes.count(messageType)) {
		this->_validMessageTypes[messageType](messageType, sender);
	}
}

void Engine::AComponent::sendToAll(Engine::Mediator::Message messageType)
{
	for (Mediator *mediator : this->_mediators) {
		if (mediator != nullptr) {
			mediator->send(messageType, this);
		}
	}
	for (Observer *observer : this->_observers) {
		if (observer != nullptr) {
			observer->receive(messageType, this);
		}
	}
}

void Engine::AComponent::addObserver(Engine::Observer *observer)
{
	this->_observers.push_back(observer);
}

void Engine::AComponent::removeObserver(Engine::Observer *observer)
{
	this->_observers.erase(std::find(this->_observers.begin(), this->_observers.end(), observer));
}

unsigned int Engine::AComponent::getParentEntityId() const
{
	return this->_parentEntity->getId();
}

Engine::AComponent::AComponent(const Engine::AComponent &other, Engine::Entity *parentEntity)
{
	this->_parentEntity = parentEntity;

	for (auto mediator : other._mediators) {
		if (mediator != &other._parentEntity->getMediator()) {
			this->registerToMediator(mediator);
		}
	}
}

Engine::AComponent &Engine::AComponent::operator=(const Engine::AComponent &other)
{
	this->_validMessageTypes = other._validMessageTypes;
	this->_observers = other._observers;
	for (auto mediator : other._mediators) {
		if (mediator != &other._parentEntity->getMediator()) {
			this->registerToMediator(mediator);
		}
	}
	return *this;
}

Engine::AComponent *Engine::AComponent::clone(Engine::Entity *	) const
{
	return nullptr;
}

