//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_HITBOX_HPP
#define RTYPE_HITBOX_HPP

#include <Common/Vector2d.hpp>

namespace Engine {
    struct Hitbox
    {
        enum Type {
            PLAYER,
            ENEMY
        };
        Vector2d bounds;
    };
}

#endif //RTYPE_HITBOX_HPP
