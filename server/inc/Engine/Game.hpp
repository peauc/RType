//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_GAME_HPP
#define RTYPE_GAME_HPP

#include <queue>
#include "World.hpp"
#include "Event.hpp"
#include "EventList.hpp"
#include "../../../RessourcesLoader/includes/RessourcesLoader.hpp"
#include "PacketList.hpp"

#define MS_PER_UPDATE 16

namespace Engine {
	class World;

	class Game
	{
	public:
		Game();
		~Game() = default;

		void run();
		void setup(int nbOfPlayers, const std::shared_ptr<RessourcesLoader> &resourceLoader);

		EventList &getEventList();
		void setWorld(std::unique_ptr<World> world);
		std::unique_ptr<World> &getWorld();
		const std::unique_ptr<World> &getWorld() const;
		const std::shared_ptr<RessourcesLoader> &getResourceLoader() const;
		void setResourceLoader(const std::shared_ptr<RessourcesLoader> &_resourceLoader);

	private:
		std::unique_ptr<World> _world;
		EventList _eventList;
		PacketList _packetList;
		std::shared_ptr<RessourcesLoader> _resourceLoader;
		bool _stop;
	};
}

#endif //RTYPE_GAME_HPP
