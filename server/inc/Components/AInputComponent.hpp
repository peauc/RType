//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_AINPUTCOMPONENT_HPP
#define RTYPE_AINPUTCOMPONENT_HPP

#include <Engine/Entity.hpp>
#include <Engine/Event.hpp>

namespace Component {
    class AInputComponent : public Engine::AComponent
    {
        std::unique_ptr<Engine::Event> event;

    public:
        explicit AInputComponent(Engine::Entity *parentEntity);
        ~AInputComponent() override = default;

        const Engine::Event &getEvent() const;
    };
}

#endif //RTYPE_AINPUTCOMPONENT_HPP
