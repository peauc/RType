//
// Created by romain on 18/01/18.
//

#include <Components/Player/PlayerWeaponComponent.hpp>

Component::PlayerWeaponComponent::PlayerWeaponComponent(Engine::Entity *parentEntity, Engine::World *parentWorld)
		: AWeaponComponent(parentEntity, parentWorld), _event(false), _firing(false), _charging(0)
{
	this->_shotAngle = 0;
	this->_cooldown = 0;
	this->_shotRelativeOrigin.x = 0;
	this->_shotRelativeOrigin.y = 0;

	this->_validMessageTypes[Engine::Mediator::Message::NEW_EVENT] = std::bind(&PlayerWeaponComponent::handleEvent,
																			   this, std::placeholders::_1,
																			   std::placeholders::_2);
}

void Component::PlayerWeaponComponent::update()
{
	if (this->_firing || (this->_charging > 0 && !this->_event)) {
		std::unique_ptr<Engine::Entity> shot = std::make_unique<Engine::Entity>();

		Engine::AComponent *shotMovementComponent = new Component::ShotMovementComponent(this->_parentEntity, 300);
		Engine::AComponent *shotGraphicsComponent;
		// TODO Change animation values
		if (this->_charging < 30) { // Regular shot
			shotGraphicsComponent = new Component::ShotGraphicsComponent(this->_parentEntity, 0, 0);
		} else { // Charged shot
			shotGraphicsComponent = new Component::ShotGraphicsComponent(this->_parentEntity, 1, 1);
		}

		if (this->_parentWorld->getCamera() != nullptr) {
			shotGraphicsComponent->addObserver(this->_parentWorld->getCamera().get());
		}

		shot->addComponent(shotMovementComponent);
		shot->addComponent(shotGraphicsComponent);

		shot->getTransformComponent().getPosition().x =
				this->_parentEntity->getTransformComponent().getPosition().x + this->_shotRelativeOrigin.x;
		shot->getTransformComponent().getPosition().y =
				this->_parentEntity->getTransformComponent().getPosition().y + this->_shotRelativeOrigin.y;

		this->_parentWorld->addObject(std::move(shot));

		this->_firing = false;
		this->_charging = 0;
	}
	this->_event = false;
}

void Component::PlayerWeaponComponent::handleEvent(Engine::Mediator::Message messageType, Engine::AComponent *sender)
{
	if (AInputComponent *inputComponent = dynamic_cast<AInputComponent *>(sender)) {
		if (inputComponent->hasEvent()) {
			this->_event = true;
			this->_firing = inputComponent->getEvent()._shotReleased;
			if (inputComponent->getEvent()._chargingShot) {
				this->_charging += inputComponent->getEvent()._chargingShot;
			}
		} else {
			this->_firing = false;
			this->_charging = 0;
		}
	}
}
