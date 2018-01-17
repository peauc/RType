//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_WORLD_HPP
#define RTYPE_WORLD_HPP

#include <list>
#include <queue>
#include <Factories/EntityFactory.hpp>
#include "Game.hpp"
#include "Sound.hpp"

namespace Engine {
	class Game;
	class World
	{
	public:
		World();
		~World() = default;

		World(const World &) = delete;
		const World &operator=(const World &) = delete;

		unsigned int addObject(Engine::Entity *(*)(unsigned int, Engine::Game &));
		unsigned int addObject(std::unique_ptr<Entity> entity);
		void removeObject(unsigned int id);
		Game *getParentGame() const;
		void setParentGame(Game *_parentGame);

		void update();

	private:
		unsigned int _nextEntityId;
		std::list<std::unique_ptr<Entity>> _objects;
		std::unique_ptr<Entity> _camera;
		std::vector<std::shared_ptr<Mediator>> _mediators;
		std::queue<Sound> _sounds;
		Game *_parentGame;
	};
}

#endif //RTYPE_WORLD_HPP
