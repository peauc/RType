//
// Created by romain on 18/01/18.
//

#include <Components/HealthComponent.hpp>
#include <Engine/Hitbox.hpp>
#include <Components/Projectiles/PlayerShotPhysicsComponent.hpp>
#include "PlayerWeaponComponent.hpp"
#include "ShotAudioComponent.hpp"

Component::PlayerWeaponComponent::PlayerWeaponComponent(Engine::Entity *parentEntity, Engine::Game *parentGame)
		: AWeaponComponent(parentEntity, parentGame, 30), _event(false), _firing(false), _charge(0), _isCharging(false)
{
	this->_shotAngle = 0;
	this->_shotRelativeOrigin.x = -50;
	this->_shotRelativeOrigin.y = 0;

	this->_validMessageTypes[Engine::Mediator::Message::NEW_EVENT] = std::bind(&PlayerWeaponComponent::handleEvent,
																			   this, std::placeholders::_1,
																			   std::placeholders::_2);
}

void Component::PlayerWeaponComponent::update() noexcept
{
	if (this->_frameSinceShot == this->_cooldown && ((!this->_isCharging && this->_charge > 0))) {
		std::unique_ptr<Engine::Entity> shot = std::make_unique<Engine::Entity>();

		Engine::AComponent *shotMovementComponent = new Component::ShotMovementComponent(shot.get(), 120, 120);
		Engine::AComponent *shotHealthComponent = new Component::HealthComponent(shot.get(),
																				 this->_parentGame->getWorld().get(),
																				 50, false, true);

		Component::ShotGraphicsComponent *shotGraphicsComponent;
		Engine::AComponent *shotSoundComponent;

		if (this->_charge < 30) { // Standard shot
			shotGraphicsComponent = new Component::ShotGraphicsComponent(shot.get(),
																		 this->_parentGame->getResourceLoader().get(),
																		 30, 30);
			shotSoundComponent = new Component::ShotAudioComponent(shot.get(), this->_parentGame, 0);
		} else { // Charged shot
			shotGraphicsComponent = new Component::ShotGraphicsComponent(shot.get(),
																		 this->_parentGame->getResourceLoader().get(),
																		 29, 29);
			shotSoundComponent = new Component::ShotAudioComponent(shot.get(), this->_parentGame, 1);
		}

		Engine::AComponent *shotPhysicsComponent = new Component::PlayerShotPhysicsComponent(shot.get(), Engine::Hitbox(
				Engine::Hitbox::Type::PLAYER_SHOT, shotGraphicsComponent->getRelativeStartPos(),
				shotGraphicsComponent->getRange()));

		if (this->_parentGame->getWorld()->getMediator() != nullptr) {
			shotPhysicsComponent->registerToMediator(this->_parentGame->getWorld()->getMediator().get());
		}

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

void Component::PlayerWeaponComponent::handleEvent(Engine::Mediator::Message, Engine::AComponent *sender) noexcept
{
	if (AInputComponent *inputComponent = dynamic_cast<AInputComponent *>(sender)) {
		if (inputComponent->hasEvent()) {
			this->_event = true;
			this->_firing = inputComponent->getEvent()._shotReleased;
			this->_isCharging = inputComponent->getEvent()._shotReleased;
			if (this->_isCharging && this->_frameSinceShot == this->_cooldown) {
				this->_charge++;
			}
		} else {
			this->_event = false;
			this->_firing = false;
			this->_isCharging = true;
		}
	}
}

Engine::AComponent *Component::PlayerWeaponComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	PlayerWeaponComponent *newComp = new PlayerWeaponComponent(parentEntity, this->_parentGame);

	*newComp = *this;

	return newComp;
}
