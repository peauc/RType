//
// Created by romain on 15/01/18.
//

#include <Components/DefaultPlayerMovementComponent.hpp>
#include <Components/DefaultPlayerInputComponent.hpp>
#include <Components/DefaultCameraMovementComponent.hpp>
#include <Components/DefaultPlayerGraphicsComponent.hpp>
#include <Components/DefaultCameraViewComponent.hpp>
#include "Factories/EntityFactory.hpp"

Engine::Entity *Factory::EntityFactory::createPlayerShip(unsigned int id, Engine::Game &game)
{
	Engine::Entity *playerShip = new Engine::Entity(id);
	Engine::AComponent *playerMoveComponent = new Component::DefaultPlayerMovementComponent(playerShip);
	Engine::AComponent *playerInputComponent = new Component::DefaultPlayerInputComponent(playerShip,
																						  game.getEventsReference());
	Engine::AComponent *playerGraphicsComponent = new Component::DefaultPlayerGraphicsComponent(playerShip);
	if (game.getWorld()->getCamera() != nullptr) {
		playerGraphicsComponent->addObserver(game.getWorld()->getCamera().get());
	}

	playerShip->addComponent(playerMoveComponent);
	playerShip->addComponent(playerInputComponent);
	playerShip->addComponent(playerGraphicsComponent);

	return playerShip;
}

Engine::Entity *Factory::EntityFactory::createCamera(unsigned int id, Engine::Game &game)
{
	Engine::Entity *camera = new Engine::Entity(id);

	camera->addComponent(new Component::DefaultCameraMovementComponent(camera, &game));
	camera->addComponent(new Component::DefaultCameraViewComponent(camera, game.getWorld().get()));

	return camera;
}
