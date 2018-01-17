//
// Created by romain on 15/01/18.
//

#include <Components/DefaultPlayerMovementComponent.hpp>
#include <Components/DefaultPlayerInputComponent.hpp>
#include <Components/DefaultCameraMovementComponent.hpp>
#include "Factories/EntityFactory.hpp"

Engine::Entity *Factory::EntityFactory::createPlayerShip(unsigned int id, Engine::Game &game)
{
	Engine::Entity *playerShip = new Engine::Entity(id);
	Engine::AComponent *playerMoveComponent = new Component::DefaultPlayerMovementComponent(playerShip);
	Engine::AComponent *playerInputComponent = new Component::DefaultPlayerInputComponent(playerShip,
																						  game.getEventsReference());

	playerShip->addComponent(playerMoveComponent);
	playerShip->addComponent(playerInputComponent);

	return playerShip;
}

Engine::Entity *Factory::EntityFactory::createCamera(unsigned int id, Engine::Game &game)
{
	Engine::Entity *camera = new Engine::Entity(id);

	camera->addComponent(new Component::DefaultCameraMovementComponent(camera, &game));

	return camera;
}
