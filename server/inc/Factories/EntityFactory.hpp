//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_FACTORY_HPP
#define RTYPE_FACTORY_HPP

#include <Engine/Entity.hpp>
#include <Components/DefaultPlayerMovementComponent.hpp>
#include <Components/DefaultPlayerInputComponent.hpp>
#include <Engine/Game.hpp>

namespace Factory {
    class EntityFactory {
        static Engine::Entity *createPlayerShip(Engine::Game &game);


    };
}

#endif //RTYPE_FACTORY_HPP
