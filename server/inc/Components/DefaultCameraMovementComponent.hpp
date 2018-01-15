//
// Created by romain on 14/01/18.
//

#ifndef RTYPE_DEFAULTCAMERAMOVEMENTCOMPONENT_HPP
#define RTYPE_DEFAULTCAMERAMOVEMENTCOMPONENT_HPP

#include <Engine/Entity.hpp>
#include <AMovementComponent.hpp>

namespace Components {
    class DefaultCameraMovementComponent : public AMovementComponent
    {
        float _speed;

    public:
        explicit DefaultCameraMovementComponent(Engine::Entity &parentEntity);
        ~DefaultCameraMovementComponent() override = default;

        void update() override;
    };
}

#endif //RTYPE_DEFAULTCAMERAMOVEMENTCOMPONENT_HPP
