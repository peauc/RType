//
// Created by romain on 17/01/18.
//

#include <Components/PlayerGraphicsComponent.hpp>
#include <iostream>

Component::PlayerGraphicsComponent::PlayerGraphicsComponent(Engine::Entity *parentEntity) :
		AGraphicsComponent(parentEntity)
{
}

void Component::PlayerGraphicsComponent::update()
{
	std::cout << "Sending GRAPHICS_REGISTERING" << std::endl;
	this->sendToAll(Engine::Mediator::Message::GRAPHICS_REGISTERING);
}
