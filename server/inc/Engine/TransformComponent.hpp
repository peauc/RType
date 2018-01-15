//
// Created by romain on 12/01/18.
//

#ifndef RTYPE_TRANSFORMCOMPONENT_HPP
#define RTYPE_TRANSFORMCOMPONENT_HPP

#include <Common/Vector2d.hpp>
#include "AComponent.hpp"

namespace Engine {
    class TransformComponent : public AComponent
    {
        Vector2d _position;
        Vector2d _rotation;

    public:
        explicit TransformComponent(Entity &parentEntity);
        ~TransformComponent() override = default;

        const Vector2d &getPosition() const;
        void setPosition(const Vector2d &_position);
        const Vector2d &getRotation() const;
        void setRotation(const Vector2d &_rotation);
    };
}

#endif //RTYPE_TRANSFORMCOMPONENT_HPP