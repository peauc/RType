//
// Created by romain on 11/01/18.
//

#include <iostream>
#include "AComponent.hpp"

void Engine::Mediator::registerComponent(AComponent *component) noexcept
{
	this->_subjects.push_back(component);
}

void Engine::Mediator::unregisterComponent(Engine::AComponent *component) noexcept
{
	auto subject = std::find(this->_subjects.begin(), this->_subjects.end(), component);
	this->_subjects.erase(subject);
}

void Engine::Mediator::send(Engine::Mediator::Message message, Engine::AComponent *sender) noexcept
{
	for (unsigned int i = 0; i < this->_subjects.size(); ++i) {
		if (_subjects[i] != sender) {
			if (_subjects[i]->isParentActive())
				_subjects[i]->receive(message, sender);
		}
	}
}
