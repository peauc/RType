//
// Created by romain on 15/01/18.
//

#include <Engine/Commands/TransformPositionCommand.hpp>

Engine::Commands::TransformPositionCommand::TransformPositionCommand(Engine::TransformComponent &transformComponent,
                                                                     float x, float y)
        : _transformComponent(transformComponent)
{
    this->_x = x;
    this->_y = y;
}

void Engine::Commands::TransformPositionCommand::execute()
{
    this->_transformComponent.getPosition().x += this->_x;
    this->_transformComponent.getPosition().y += this->_y;
}
