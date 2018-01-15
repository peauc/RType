//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP
#define RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/Event.hpp>
#include <queue>
#include "AInputComponent.hpp"

namespace Component {
    class DefaultPlayerInputComponent : public AInputComponent
    {
        std::vector<std::unique_ptr<Engine::Event>> &_gameEvents;
        std::unique_ptr<Engine::Event> _event;

    public:
        explicit DefaultPlayerInputComponent(Engine::Entity &parentEntity, std::vector<std::unique_ptr<Engine::Event>> &gameEvents);
        ~DefaultPlayerInputComponent() override = default;

        void update() override;

        const Engine::Event &getEvent() const;
    };
}

#endif //RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP