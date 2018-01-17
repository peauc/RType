//
// Created by romain on 17/01/18.
//

#include <Components/DefaultPlayerGraphicsComponent.hpp>
#include <iostream>

Component::DefaultPlayerGraphicsComponent::DefaultPlayerGraphicsComponent(Engine::Entity *parentEntity) :
		AGraphicsComponent(parentEntity)
{
}

void Component::DefaultPlayerGraphicsComponent::update()
{
	std::cout << "Sending GRAPHICS_REGISTERING" << std::endl;
	this->sendToAll(Engine::Mediator::Message::GRAPHICS_REGISTERING);
}
