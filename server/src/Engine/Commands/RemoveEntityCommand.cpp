//
// Created by romain on 21/01/18.
//

#include <Engine/Commands/RemoveEntityCommand.hpp>

Engine::Commands::RemoveEntityCommand::RemoveEntityCommand(Engine::World &world, unsigned int entityId) :
		_world(world), _entityId(entityId)
{
}

void Engine::Commands::RemoveEntityCommand::execute()
{
	this->_world.removeObject(this->_entityId);
}
