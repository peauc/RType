//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_DEFAULTPHYSICSCOMPONENT_HPP
#define RTYPE_DEFAULTPHYSICSCOMPONENT_HPP

#include <Engine/AComponent.hpp>

namespace Component {
    class DefaultPhysicsComponent : public Engine::AComponent
    {
        Vector2d hitbox;
    };
}

#endif //RTYPE_DEFAULTPHYSICSCOMPONENT_HPP
