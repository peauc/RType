//
// Created by romain on 17/01/18.
//

#include <Components/CameraViewComponent.hpp>
#include <iostream>

Component::CameraViewComponent::CameraViewComponent(Engine::Entity *parentEntity,
													Engine::World *parentWorld) :
		AComponent(parentEntity), _parentWorld(parentWorld)
{
	this->_relativeTopLeft.x = 0;
	this->_relativeTopLeft.y = 0;
	this->_relativeBottomRight.x = 1900;
	this->_relativeBottomRight.y = 1080;

	//this->_validMessageTypes[Engine::Mediator::Message::GRAPHICS_REGISTERING] = &CameraViewComponent::handleGraphicsRegistration;
}

void Component::CameraViewComponent::update()
{
	for (AGraphicsComponent *component : this->_graphicComponents) {
		if (component != nullptr) {
			if (component->isInArea(this->_parentEntity->getTransformComponent().getPosition().x,
									this->_parentEntity->getTransformComponent().getPosition().y,
									this->_relativeBottomRight.x, this->_relativeBottomRight.y)) {
				std::cout << "Adding object" << std::endl;
				// ADD object to world display list
			}
		}
	}
}

void Component::CameraViewComponent::handleGraphicsRegistration(Engine::Mediator::Message messageType,
																Engine::AComponent *sender)
{
	if (AGraphicsComponent *graphicsComponent = dynamic_cast<AGraphicsComponent *>(sender)) {
		this->_graphicComponents.push_back(graphicsComponent);
	}
}