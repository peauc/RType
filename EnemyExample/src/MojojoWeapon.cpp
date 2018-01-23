//
// Created by romain on 18/01/18.
//

#include <Components/HealthComponent.hpp>
#include "MojojoWeapon.hpp"
#include "AInputComponent.hpp"
#include "ShotAudioComponent.hpp"
#include "ShotMovementComponent.hpp"
#include "ShotGraphicsComponent.hpp"

Component::MojojoWeapon::MojojoWeapon(Engine::Entity *parentEntity, Engine::Game *parentGame)
		: AWeaponComponent(parentEntity, parentGame, 60), _event(false), _firing(false), _charge(0), _isCharging(false)
{
	this->_shotAngle = 180;
	this->_shotRelativeOrigin.x = 0;
	this->_shotRelativeOrigin.y = 0;

	this->_validMessageTypes[Engine::Mediator::Message::NEW_EVENT] = std::bind(&MojojoWeapon::handleEvent,
																			   this, std::placeholders::_1,
																			   std::placeholders::_2);
}

void Component::MojojoWeapon::update() noexcept
{
	if (this->_frameSinceShot == this->_cooldown && (this->_firing || (!this->_isCharging && this->_charge > 0))) {
		std::unique_ptr<Engine::Entity> shot = std::make_unique<Engine::Entity>();

		Engine::AComponent *shotMovementComponent = new Component::ShotMovementComponent(shot.get(), 120, 120);
		Engine::AComponent *shotHealthComponent = new Component::HealthComponent(shot.get(),
																				 this->_parentGame->getWorld().get(),
																				 50, false, true);
		Engine::AComponent *shotGraphicsComponent;
		Engine::AComponent *shotSoundComponent;

		shotGraphicsComponent = new Component::ShotGraphicsComponent(shot.get(),
																		 this->_parentGame->getResourceLoader().get(),
																		 31, 31);
		shotSoundComponent = new Component::ShotAudioComponent(shot.get(), this->_parentGame, 0);
		if (this->_parentGame->getWorld()->getCamera() != nullptr) {
			shotGraphicsComponent->addObserver(this->_parentGame->getWorld()->getCamera().get());
		}

		shot->addComponent(shotMovementComponent);
		shot->addComponent(shotGraphicsComponent);
		shot->addComponent(shotSoundComponent);
		shot->addComponent(shotHealthComponent);

		shot->getTransformComponent().getPosition().x =
				this->_parentEntity->getTransformComponent().getPosition().x + this->_shotRelativeOrigin.x;
		shot->getTransformComponent().getPosition().y =
				this->_parentEntity->getTransformComponent().getPosition().y + this->_shotRelativeOrigin.y;

		shot->setActive(true);

		this->_parentGame->getWorld()->addObject(std::move(shot));

		this->_frameSinceShot = 0;
		this->_charge = 0;
	} else if (this->_frameSinceShot < this->_cooldown) {
		this->_frameSinceShot++;
	}
	this->_event = false;
	this->_firing = false;
	this->_isCharging = false;
}

void Component::MojojoWeapon::handleEvent(Engine::Mediator::Message, Engine::AComponent *sender) noexcept
{
	if (AInputComponent *inputComponent = dynamic_cast<AInputComponent *>(sender)) {
		if (inputComponent->hasEvent()) {
			this->_event = true;
			this->_firing = inputComponent->getEvent()._shotReleased;
			this->_isCharging = inputComponent->getEvent()._chargingShot;
			if (this->_isCharging) {
				this->_charge++;
			}
		} else {
			this->_event = false;
			this->_firing = false;
			this->_isCharging = false;
		}
	}
}

Engine::AComponent *Component::MojojoWeapon::clone(Engine::Entity *parentEntity) const noexcept
{
	MojojoWeapon *newComp = new MojojoWeapon(parentEntity, this->_parentGame);

	*newComp = *this;

	return newComp;
}
