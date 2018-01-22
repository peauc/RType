//
// Created by romain on 17/01/18.
//

#include "Components/Camera/CameraViewComponent.hpp"
#include "Factories/PacketFactory.hpp"

Component::CameraViewComponent::CameraViewComponent(Engine::Entity *parentEntity,
													Engine::Game *parentGame) :
		AComponent(parentEntity), _parentGame(parentGame)
{
	this->_relativeTopLeft.x = 0;
	this->_relativeTopLeft.y = 0;
	this->_relativeBottomRight.x = 8000;
	this->_relativeBottomRight.y = 6000;

	this->_validMessageTypes[Engine::Mediator::Message::GRAPHICS_REGISTERING] = std::bind(
			&CameraViewComponent::handleGraphicsRegistration,
			this, std::placeholders::_1,
			std::placeholders::_2);
}

void Component::CameraViewComponent::update() noexcept
{
	for (AGraphicsComponent *component : this->_graphicComponents) {
		if (component != nullptr) {
			if (component->isInArea(this->_parentEntity->getTransformComponent().getPosition().x,
									this->_parentEntity->getTransformComponent().getPosition().y,
									this->_relativeBottomRight.x, this->_relativeBottomRight.y)) {
				std::cout << "OBJECT IN SIGHT" << std::endl;
				this->_parentGame->pushDataPacket(PacketFactory::createObjectPacket(
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
	this->_graphicComponents.clear();
}

void Component::CameraViewComponent::handleGraphicsRegistration(Engine::Mediator::Message,
																Engine::AComponent *sender) noexcept
{
	if (AGraphicsComponent *graphicsComponent = dynamic_cast<AGraphicsComponent *>(sender)) {
		this->_graphicComponents.push_back(graphicsComponent);
	}
}

const Vector2d &Component::CameraViewComponent::getRelativeBottomRight() const noexcept
{
	return _relativeBottomRight;
}
