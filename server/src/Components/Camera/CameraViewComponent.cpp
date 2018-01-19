//
// Created by romain on 17/01/18.
//

#include <Components/Camera/CameraViewComponent.hpp>
#include <iostream>
#include <Factories/PacketFactory.hpp>

Component::CameraViewComponent::CameraViewComponent(Engine::Entity *parentEntity,
													Engine::World *parentWorld) :
		AComponent(parentEntity), _parentWorld(parentWorld)
{
	this->_relativeTopLeft.x = 0;
	this->_relativeTopLeft.y = 0;
	this->_relativeBottomRight.x = 19000;
	this->_relativeBottomRight.y = 10800;

	this->_validMessageTypes[Engine::Mediator::Message::GRAPHICS_REGISTERING] = std::bind(
			&CameraViewComponent::handleGraphicsRegistration,
			this, std::placeholders::_1,
			std::placeholders::_2);
}

void Component::CameraViewComponent::update()
{
	for (AGraphicsComponent *component : this->_graphicComponents) {
		if (component != nullptr) {
			std::cout << "Checking sight" << std::endl;
			if (component->isInArea(this->_parentEntity->getTransformComponent().getPosition().x,
									this->_parentEntity->getTransformComponent().getPosition().y,
									this->_relativeBottomRight.x, this->_relativeBottomRight.y)) {
				std::cout << "Adding object" << std::endl;
				this->_parentWorld->addPacketToSend(PacketFactory::createObjectPacket(
						static_cast<short>(
								component->getRelativeXPos(this->_parentEntity->getTransformComponent().getPosition().x,
														   this->_relativeBottomRight.x) * 100.0f),
						static_cast<short>(
								component->getRelativeYPos(this->_parentEntity->getTransformComponent().getPosition().y,
														   this->_relativeBottomRight.y) * 100.0f),
						component->isAlive() ? Packet::EntityState::ALIVE : Packet::EntityState::DEAD,
						component->isHit(),
						component->getParentEntityId(),
						component->getCurrentAnimationId()
				));
				component->setIsHit(false);
			}
		}
	}
}

void Component::CameraViewComponent::handleGraphicsRegistration(Engine::Mediator::Message messageType,
																Engine::AComponent *sender)
{
	std::cout << "handling graphics registration" << std::endl;
	if (AGraphicsComponent *graphicsComponent = dynamic_cast<AGraphicsComponent *>(sender)) {
		this->_graphicComponents.push_back(graphicsComponent);
	}
}