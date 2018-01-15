//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_TRANSFORMPOSITIONCOMMAND_HPP
#define RTYPE_TRANSFORMPOSITIONCOMMAND_HPP

#include <Engine/TransformComponent.hpp>
#include "ICommand.hpp"

namespace Engine {
    namespace Commands {
        class TransformPositionCommand : public ICommand
        {
            Engine::TransformComponent &_transformComponent;
            float _x;
            float _y;

        public:
            explicit TransformPositionCommand(Engine::TransformComponent &transformComponent, float x, float y);
            ~TransformPositionCommand() = default;

            void execute() override;
        };
    }
}

#endif //RTYPE_TRANSFORMPOSITIONCOMMAND_HPP
