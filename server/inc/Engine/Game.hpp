//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_GAME_HPP
#define RTYPE_GAME_HPP

#include <queue>
#include "World.hpp"
#include "Event.hpp"
#include "../../../RessourcesLoader/includes/RessourcesLoader.hpp"

#define MS_PER_UPDATE 16

namespace Engine {
	class World;
	class Game
	{
	public:
		Game();
		~Game() = default;
		void run();

		std::vector<std::unique_ptr<Event>> &getEventsReference();
		const std::vector<std::unique_ptr<Event>> &getEvents() const;
		std::unique_ptr<World> &getWorld();
		const std::unique_ptr<World> &getWorld() const;
		void setWorld(std::unique_ptr<World>);
		const std::shared_ptr<RessourcesLoader> &getResourceLoader() const;
		void setResourceLoader(const std::shared_ptr<RessourcesLoader> &_resourceLoader);

	private:
		std::unique_ptr<World> _world;
		std::vector<std::unique_ptr<Event>> _events;
		std::shared_ptr<RessourcesLoader> _resourceLoader;
		bool _stop;
	};
}

#endif //RTYPE_GAME_HPP
