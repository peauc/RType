//
// Created by romain on 15/01/18.
//

#include <Components/Abstracts/AInputComponent.hpp>
#include <iostream>

Component::AInputComponent::AInputComponent(Engine::Entity *parentEntity) : AComponent(parentEntity)
{
}

const Engine::Event &Component::AInputComponent::getEvent() const
{
	return *this->_event;
}

bool Component::AInputComponent::hasEvent() const
{
	return this->_event != nullptr;
}

Component::AInputComponent &Component::AInputComponent::operator=(const Component::AInputComponent &)
{
	this->_event = nullptr;

	return *this;
}
