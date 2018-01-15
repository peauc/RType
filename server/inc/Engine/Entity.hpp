//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_ENTITY_HPP
#define RTYPE_ENTITY_HPP

#include <vector>
#include <memory>
#include "AComponent.hpp"
#include "TransformComponent.hpp"

namespace Engine {
    class Entity
    {
        unsigned int _id;
        TransformComponent _transformComponent;
        std::vector<std::unique_ptr<AComponent>> _components;
        Mediator _mediator;

    public:
        Entity(unsigned int hp, float speed);
        ~Entity() = default;

        void update();
        void addComponent(AComponent *component);
        const Mediator &getMediator() const;
        const TransformComponent &getTransformComponent() const;
        const unsigned int getId() const;
    };
}

#endif //RTYPE_ENTITY_HPP
