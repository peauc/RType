//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_FACTORY_HPP
#define RTYPE_FACTORY_HPP

#include "Entity.hpp"
#include "Game.hpp"

namespace Engine {
	class Game;
}

typedef Engine::Entity *(*createCall)(unsigned int, Engine::Game &);

namespace Factory {
	class EntityFactory
	{
	public:
		static Engine::Entity *createPlayerShip(unsigned int id, Engine::Game &game) noexcept;
		static Engine::Entity *createCamera(unsigned int id, Engine::Game &game) noexcept;
		static Engine::Entity *createZone(unsigned int id, Engine::Game &game, const Vector2d &size) noexcept;
	};
}

#endif //RTYPE_FACTORY_HPP
