//
// Created by romain on 15/01/18.
//

#include "AInputComponent.hpp"

Component::AInputComponent::AInputComponent(Engine::Entity *parentEntity) : AComponent(parentEntity)
{
}

const Engine::Event &Component::AInputComponent::getEvent() const noexcept
{
	return *this->_event;
}

bool Component::AInputComponent::hasEvent() const noexcept
{
	return this->_event != nullptr;
}

Component::AInputComponent &Component::AInputComponent::operator=(const Component::AInputComponent &) noexcept
{
	this->_event = nullptr;

	return *this;
}
