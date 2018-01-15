//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_AMOVEMENTCOMPONENT_HPP
#define RTYPE_AMOVEMENTCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/Event.hpp>

namespace Component {
    class AMovementComponent : public Engine::AComponent
    {
    protected:
        std::unique_ptr<Engine::Event> _event;

    public:
        explicit AMovementComponent(Engine::Entity &parentEntity);
        ~AMovementComponent() override = default;
    };
}

#endif //RTYPE_AMOVEMENTCOMPONENT_HPP
