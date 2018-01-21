//
// Created by romain on 21/01/18.
//

#include <Engine/Entity.hpp>
#include <Engine/Game.hpp>
#include <Engine/Zone.hpp>

Engine::Entity *Engine::MapLoader::Zone::createZone(Game &game) const
{
}

Engine::Entity *Engine::MapLoader::Zone::ZoneObject::createEntity(Engine::Game &game) const
{
	return game.cloneEntity(this->_libname);
}
