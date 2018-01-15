//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_MEDIATOR_HPP
#define RTYPE_MEDIATOR_HPP

#include <vector>
#include <algorithm>
#include "AComponent.hpp"
#include "Message.hpp"

namespace Engine {
    class AComponent;
    class Mediator
    {
        std::vector<AComponent &> _subjects;

    public:
        Mediator() = default;
        ~Mediator() = default;

        void send(Message message, AComponent *sender);
        void registerComponent(AComponent &component);
        void unregisterComponent(AComponent &component);
    };
}

#endif //RTYPE_MEDIATOR_HPP
