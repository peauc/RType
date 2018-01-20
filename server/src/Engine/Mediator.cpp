//
// Created by romain on 11/01/18.
//

#include <Engine/AComponent.hpp>
#include <Engine/Mediator.hpp>
#include <iostream>

void Engine::Mediator::registerComponent(AComponent *component)
{
	this->_subjects.push_back(component);
}

void Engine::Mediator::unregisterComponent(Engine::AComponent *component)
{
	this->_subjects.erase(std::find(this->_subjects.begin(), this->_subjects.end(), component));
}

void Engine::Mediator::send(Engine::Mediator::Message message, Engine::AComponent *sender)
{
	for (unsigned int i = 0; i < this->_subjects.size(); ++i) {
		if (_subjects[i] != sender) {
			_subjects[i]->receive(message, sender);
		}
	}
}
