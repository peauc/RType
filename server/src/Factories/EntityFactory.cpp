//
// Created by romain on 15/01/18.
//

#include <Components/Player/PlayerMovementComponent.hpp>
#include <Components/Player/PlayerInputComponent.hpp>
#include <Components/Camera/CameraMovementComponent.hpp>
#include <Components/Player/PlayerGraphicsComponent.hpp>
#include <Components/Camera/CameraViewComponent.hpp>
#include <iostream>
#include <Components/Player/PlayerWeaponComponent.hpp>
#include <Components/Player/PlayerPhysicsComponent.hpp>
#include "Factories/EntityFactory.hpp"

Engine::Entity *Factory::EntityFactory::createPlayerShip(unsigned int id, Engine::Game &game)
{

	Engine::Entity *playerShip = new Engine::Entity(id);

	Engine::AComponent *playerMoveComponent = new Component::PlayerMovementComponent(playerShip);
	Engine::AComponent *playerInputComponent = new Component::PlayerInputComponent(playerShip,
																				   game.getEventList());
	Component::PlayerGraphicsComponent *playerGraphicsComponent = new Component::PlayerGraphicsComponent(playerShip,
																										 game.getResourceLoader().get());
	Engine::AComponent *playerWeaponComponent = new Component::PlayerWeaponComponent(playerShip, &game);

	if (game.getWorld()->getCamera() != nullptr) {
		playerGraphicsComponent->addObserver(game.getWorld()->getCamera().get());
	}

	Engine::AComponent *playerPhysicsComponent = new Component::PlayerPhysicsComponent(playerShip, Engine::Hitbox(
			Engine::Hitbox::Type::PLAYER, playerGraphicsComponent->getRelativeStartPos(),
			playerGraphicsComponent->getRange()));
	if (game.getWorld()->getMediator() != nullptr) {
		playerPhysicsComponent->registerToMediator(game.getWorld()->getMediator().get());
	}

	playerShip->addComponent(playerInputComponent);
	playerShip->addComponent(playerMoveComponent);
	playerShip->addComponent(playerWeaponComponent);
	playerShip->addComponent(playerPhysicsComponent);
	playerShip->addComponent(playerGraphicsComponent);

	playerShip->getTransformComponent().getPosition().x = 0;
	playerShip->getTransformComponent().getPosition().y = 2000 + id * 2000;

	return playerShip;
}

Engine::Entity *Factory::EntityFactory::createCamera(unsigned int id, Engine::Game &game)
{
	Engine::Entity *camera = new Engine::Entity(id);

	camera->addComponent(new Component::CameraMovementComponent(camera, &game));
	camera->addComponent(new Component::CameraViewComponent(camera, &game));

	return camera;
}
