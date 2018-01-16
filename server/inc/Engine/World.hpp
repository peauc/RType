//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_WORLD_HPP
#define RTYPE_WORLD_HPP

#include <list>
#include <queue>
#include "Entity.hpp"
#include "Mediator.hpp"
#include "Sound.hpp"

namespace Engine {
	class World
	{
	public:
		World() = default;
		~World() = default;

		World(const World &) = delete;
		const World &operator=(const World &) = delete;

		void addObject(std::unique_ptr<Entity> &&entity);
		void removeObject(unsigned int id);

		void update();

	private:
		std::list<std::unique_ptr<Entity>> _objects;
		std::vector<std::shared_ptr<Mediator>> _mediators;
		std::queue<Sound> _sounds;
	};
}

#endif //RTYPE_WORLD_HPP
