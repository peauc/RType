//
// Created by romain on 18/01/18.
//

#include <Components/Player/PlayerWeaponComponent.hpp>
#include <Components/Projectiles/ShotAudioComponent.hpp>
#include <iostream>

Component::PlayerWeaponComponent::PlayerWeaponComponent(Engine::Entity *parentEntity, Engine::Game *parentGame)
		: AWeaponComponent(parentEntity, parentGame), _event(false), _firing(false), _charging(0)
{
	this->_shotAngle = 0;
	this->_cooldown = 0;
	this->_shotRelativeOrigin.x = 0;
	this->_shotRelativeOrigin.y = 0;

	this->_validMessageTypes[Engine::Mediator::Message::NEW_EVENT] = std::bind(&PlayerWeaponComponent::handleEvent,
																			   this, std::placeholders::_1,
																			   std::placeholders::_2);
}

void Component::PlayerWeaponComponent::update() noexcept
{
	if (this->_firing || (this->_charging > 0 && !this->_event)) {
		std::unique_ptr<Engine::Entity> shot = std::make_unique<Engine::Entity>();

		Engine::AComponent *shotMovementComponent = new Component::ShotMovementComponent(this->_parentEntity, 300);
		Engine::AComponent *shotGraphicsComponent;
		Engine::AComponent *shotSoundComponent;
		// TODO Change animation values
		if (this->_charging < 30) { // Regular shot
			shotGraphicsComponent = new Component::ShotGraphicsComponent(this->_parentEntity,
																		 this->_parentGame->getResourceLoader().get(),
																		 19, 19);
			shotSoundComponent = new Component::ShotAudioComponent(this->_parentEntity, this->_parentGame, 0);
		} else { // Charged shot
			shotGraphicsComponent = new Component::ShotGraphicsComponent(this->_parentEntity,
																		 this->_parentGame->getResourceLoader().get(),
																		 19, 19);
			shotSoundComponent = new Component::ShotAudioComponent(this->_parentEntity, this->_parentGame, 1);
		}

		if (this->_parentGame->getWorld()->getCamera() != nullptr) {
			shotGraphicsComponent->addObserver(this->_parentGame->getWorld()->getCamera().get());
		}

		shot->addComponent(shotMovementComponent);
		shot->addComponent(shotGraphicsComponent);
		shot->addComponent(shotSoundComponent);

		shot->getTransformComponent().getPosition().x =
				this->_parentEntity->getTransformComponent().getPosition().x + this->_shotRelativeOrigin.x;
		shot->getTransformComponent().getPosition().y =
				this->_parentEntity->getTransformComponent().getPosition().y + this->_shotRelativeOrigin.y;

		this->_parentGame->getWorld()->addObject(std::move(shot));

		this->_firing = false;
		this->_charging = 0;
	}
	this->_event = false;
}

void Component::PlayerWeaponComponent::handleEvent(Engine::Mediator::Message, Engine::AComponent *sender) noexcept
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

Engine::AComponent *Component::PlayerWeaponComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	PlayerWeaponComponent *newComp = new PlayerWeaponComponent(parentEntity, this->_parentGame);

	*newComp = *this;

	return newComp;
}
