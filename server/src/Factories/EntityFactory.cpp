//
// Created by romain on 15/01/18.
//

#include "Factories/EntityFactory.hpp"

Engine::Entity *Factory::EntityFactory::createPlayerShip(Engine::Game &game)
{
    Engine::Entity *playerShip = new Engine::Entity();
    Engine::AComponent *playerMoveComponent = new Component::DefaultPlayerMovementComponent(playerShip);
    Engine::AComponent *playerInputComponent = new Component::DefaultPlayerInputComponent(playerShip, game.getEventsReference());

    playerShip->addComponent(playerMoveComponent);
    playerShip->addComponent(playerInputComponent);
}
