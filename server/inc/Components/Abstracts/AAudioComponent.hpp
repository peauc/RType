//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_AAUDIOCOMPONENT_HPP
#define RTYPE_AAUDIOCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/World.hpp>

namespace Component {
    class AAudioComponent : public Engine::AComponent
    {
    public:
        explicit AAudioComponent(Engine::Entity *parentEntity, Engine::World *parentWorld);
        ~AAudioComponent() override = default;

		void addSoundPacket(unsigned char soundId, bool repeat);
    protected:
        Engine::World *_parentWorld;
        std::vector<unsigned char> _soundIds;
    };
}

#endif //RTYPE_AAUDIOCOMPONENT_HPP