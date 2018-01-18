//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_AAUDIOCOMPONENT_HPP
#define RTYPE_AAUDIOCOMPONENT_HPP

#include <Engine/AComponent.hpp>

namespace Components {
    class AAudioComponents : public Engine::AComponent
    {
    public:
        explicit AAudioComponents(Engine::Entity *parentEntity);
        ~AAudioComponents() override = default;

    protected:
        std::vector<unsigned char> _soundIds;
    };
}

#endif //RTYPE_AAUDIOCOMPONENT_HPP
