//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_WORLD_HPP
#define RTYPE_WORLD_HPP

#include <list>
#include <queue>
#include <Factories/EntityFactory.hpp>
#include "Game.hpp"

namespace Engine {
	class Game;

	class World
	{
	public:
		World();
		~World() = default;

		World(const World &) = delete;
		const World &operator=(const World &) = delete;

		unsigned int addObject(Engine::Entity *(*)(unsigned int, Engine::Game &))  noexcept;
		unsigned int addObject(std::unique_ptr<Entity> entity)  noexcept;
		void removeObject(unsigned int id)  noexcept;
		Game *getParentGame() const noexcept;
		void setParentGame(Game *_parentGame)  noexcept;

		std::unique_ptr<Entity> &getCamera()  noexcept;
		void setCamera(std::unique_ptr<Entity> camera)  noexcept;
		std::unique_ptr<Mediator> &getMediator()  noexcept;
		const std::unique_ptr<Mediator> &getMediator() const noexcept;
		void addMediator()  noexcept;
		const std::list<std::unique_ptr<Entity>> &getObjects() const noexcept ;

		void update() noexcept;

	private:
		unsigned int _nextEntityId;
		std::list<std::unique_ptr<Entity>> _objects;
		std::unique_ptr<Entity> _camera;
		std::unique_ptr<Mediator> _mediator;
		Game *_parentGame;
	};
}

#endif //RTYPE_WORLD_HPP
