//
// Created by romain on 15/01/18.
//

#include <Components/PlayerMovementComponent.hpp>
#include <Components/PlayerInputComponent.hpp>
#include <Components/CameraMovementComponent.hpp>
#include <Components/PlayerGraphicsComponent.hpp>
#include <Components/CameraViewComponent.hpp>
#include <Components/PlayerPhysicsComponent.hpp>
#include "Factories/EntityFactory.hpp"

Engine::Entity *Factory::EntityFactory::createPlayerShip(unsigned int id, Engine::Game &game)
{
	Engine::Entity *playerShip = new Engine::Entity(id);

	Engine::AComponent *playerMoveComponent = new Component::PlayerMovementComponent(playerShip);
	Engine::AComponent *playerInputComponent = new Component::PlayerInputComponent(playerShip,
																						  game.getEventsReference());
	Engine::AComponent *playerGraphicsComponent = new Component::PlayerGraphicsComponent(playerShip);
	if (game.getWorld()->getCamera() != nullptr) {
		playerGraphicsComponent->addObserver(game.getWorld()->getCamera().get());
	}
	Engine::AComponent *playerPhysicsComponent = new Component::PlayerPhysicsComponent(playerShip);
	if (game.getWorld()->getMediator() != nullptr) {
		playerPhysicsComponent->registerToMediator(game.getWorld()->getMediator().get());
	}

	playerShip->addComponent(playerMoveComponent);
	playerShip->addComponent(playerInputComponent);
	playerShip->addComponent(playerGraphicsComponent);
	playerShip->addComponent(playerPhysicsComponent);

	return playerShip;
}

Engine::Entity *Factory::EntityFactory::createCamera(unsigned int id, Engine::Game &game)
{
	Engine::Entity *camera = new Engine::Entity(id);

	camera->addComponent(new Component::CameraMovementComponent(camera, &game));
	camera->addComponent(new Component::CameraViewComponent(camera, game.getWorld().get()));

	return camera;
}
