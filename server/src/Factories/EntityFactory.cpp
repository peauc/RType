//
// Created by romain on 15/01/18.
//

#include "Components/Player/PlayerMovementComponent.hpp"
#include "Components/Player/PlayerInputComponent.hpp"
#include "Components/Player/PlayerWeaponComponent.hpp"
#include "Components/Player/PlayerPhysicsComponent.hpp"
#include "Components/Player/PlayerGraphicsComponent.hpp"
#include "Components/Camera/CameraMovementComponent.hpp"
#include "Components/Camera/CameraViewComponent.hpp"
#include "Components/Camera/CameraZoneComponent.hpp"
#include "Components/Zone/ZoneComponent.hpp"
#include "Components/HealthComponent.hpp"

Engine::Entity *Factory::EntityFactory::createPlayerShip(unsigned int id, Engine::Game &game) noexcept
{

	Engine::Entity *playerShip = new Engine::Entity(id);

	Engine::AComponent *playerMoveComponent = new Component::PlayerMovementComponent(playerShip);
	Engine::AComponent *playerInputComponent = new Component::PlayerInputComponent(playerShip,
																				   &game.getEventList());
	Component::PlayerGraphicsComponent *playerGraphicsComponent = new Component::PlayerGraphicsComponent(playerShip,
																										 game.getResourceLoader().get());
	Engine::AComponent *playerWeaponComponent = new Component::PlayerWeaponComponent(playerShip, &game);

	Engine::AComponent *playerPhysicsComponent = new Component::PlayerPhysicsComponent(playerShip, Engine::Hitbox(
			Engine::Hitbox::Type::PLAYER, playerGraphicsComponent->getRelativeStartPos(),
			playerGraphicsComponent->getRange()));

	Engine::AComponent *playerHealthComponent = new Component::HealthComponent(playerShip, game.getWorld().get(), 100, false, true);

	playerShip->addComponent(playerInputComponent);
	playerShip->addComponent(playerMoveComponent);
	playerShip->addComponent(playerWeaponComponent);
	playerShip->addComponent(playerPhysicsComponent);
	playerShip->addComponent(playerGraphicsComponent);
	playerShip->addComponent(playerHealthComponent);

	if (game.getWorld()->getMediator() != nullptr) {
		playerPhysicsComponent->registerToMediator(game.getWorld()->getMediator().get());
	}

	if (game.getWorld()->getCamera() != nullptr) {
		playerGraphicsComponent->addObserver(game.getWorld()->getCamera().get());
	}

	playerShip->getTransformComponent().getPosition().x = 1000;
	playerShip->getTransformComponent().getPosition().y = 2000 + id * 2000;

	playerShip->setActive(true);

	return playerShip;
}

Engine::Entity *Factory::EntityFactory::createCamera(unsigned int id, Engine::Game &game) noexcept
{
	Engine::Entity *camera = new Engine::Entity(id);

	Engine::AComponent *movementComponent = new Component::CameraMovementComponent(camera, &game);
	Component::CameraViewComponent *viewComponent = new Component::CameraViewComponent(camera, &game);
	Engine::AComponent *zoneComponent = new Component::CameraZoneComponent(camera,
																		   Engine::Hitbox(Engine::Hitbox::CAMERA,
																						  Vector2d(0, 0),
																						  Vector2d(
																								  viewComponent->getRelativeBottomRight())));
	camera->addComponent(movementComponent);
	camera->addComponent(viewComponent);
	camera->addComponent(zoneComponent);

	if (game.getWorld()->getMediator() != nullptr) {
		zoneComponent->registerToMediator(game.getWorld()->getMediator().get());
	}

	camera->setActive(true);

	return camera;
}

Engine::Entity *Factory::EntityFactory::createZone(unsigned int id, Engine::Game &game, const Vector2d &size) noexcept
{
	Engine::Entity *zone = new Engine::Entity(id);

	Component::ZoneComponent *zoneComponent = new Component::ZoneComponent(zone,
																		   Engine::Hitbox(Engine::Hitbox::ZONE,
																						  Vector2d(0, 0), size),
																		   game.getWorld().get());

	zone->addComponent(zoneComponent);

	if (game.getWorld()->getMediator() != nullptr) {
		zoneComponent->registerToMediator(game.getWorld()->getMediator().get());
	}

	zone->setActive(true);

	return zone;
}
