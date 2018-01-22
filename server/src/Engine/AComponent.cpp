//
// Created by romain on 12/01/18.
//

#include <iostream>
#include "AComponent.hpp"
#include "Entity.hpp"

Engine::AComponent::AComponent(Engine::Entity *parentEntity) : _parentEntity(parentEntity)
{
}

void Engine::AComponent::registerToMediator(Engine::Mediator *mediator) noexcept
{
	this->_mediators.push_back(mediator);
	mediator->registerComponent(this);
}

void Engine::AComponent::unregisterToMediator(Engine::Mediator *mediator) noexcept
{
	std::cout << "1" << std::endl;
	this->_mediators.erase(std::find(this->_mediators.begin(), this->_mediators.end(), mediator));
	std::cout << "2" << std::endl;
	mediator->unregisterComponent(this);
	std::cout << "3" << std::endl;
}

void Engine::AComponent::receive(Engine::Mediator::Message messageType, Engine::AComponent *sender) noexcept
{
	if (this->_validMessageTypes.count(messageType)) {
		this->_validMessageTypes[messageType](messageType, sender);
	}
}

void Engine::AComponent::sendToAll(Engine::Mediator::Message messageType) noexcept
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

void Engine::AComponent::sendToParentEntity(Engine::Mediator::Message messageType) noexcept
{
	if (this->_mediators[0] != nullptr) {
		this->_mediators[0]->send(messageType, this);
	}
}

void Engine::AComponent::addObserver(Engine::Observer *observer) noexcept
{
	this->_observers.push_back(observer);
}

void Engine::AComponent::removeObserver(Engine::Observer *observer) noexcept
{
	this->_observers.erase(std::find(this->_observers.begin(), this->_observers.end(), observer));
}

unsigned int Engine::AComponent::getParentEntityId() const noexcept
{
	return this->_parentEntity->getId();
}

bool Engine::AComponent::isParentActive() const noexcept
{
	return this->_parentEntity->isActive();
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

Engine::AComponent &Engine::AComponent::operator=(const Engine::AComponent &other) noexcept
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

Engine::AComponent *Engine::AComponent::clone(Engine::Entity *) const noexcept
{
	return nullptr;
}

void Engine::AComponent::unregisterFromMediators() noexcept
{
	for (auto mediator : this->_mediators) {
		this->unregisterToMediator(mediator);
	}
}
