//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_APHYSICSCOMPONENT_HPP
#define RTYPE_APHYSICSCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/Hitbox.hpp>

namespace Component {
    class APhysicsComponent : public Engine::AComponent
    {
        Engine::Hitbox hitbox;

    public:
        APhysicsComponent(Engine::Entity *entity);
        virtual ~APhysicsComponent();
    };
}

#endif //RTYPE_APHYSICSCOMPONENT_HPP
