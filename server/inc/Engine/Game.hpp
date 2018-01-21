//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_GAME_HPP
#define RTYPE_GAME_HPP

#include <thread>
#include <queue>
#include "World.hpp"
#include "Event.hpp"
#include "EventList.hpp"
#include "EnemyLoader.hpp"
#include "../../../RessourcesLoader/includes/RessourcesLoader.hpp"
#include "PacketList.hpp"

namespace Engine {
	class World;

	class Game
	{
	public:
		const long NS_PER_UPDATE = 16000000;

		Game();
		~Game();

		void start();
		void run();
		void setup(size_t nbOfPlayers,
				   const std::shared_ptr<RessourcesLoader> &resourceLoader);

		EventList &getEventList();
		void setWorld(std::unique_ptr<World> world);
		std::unique_ptr<World> &getWorld();
		const std::unique_ptr<World> &getWorld() const;
		const std::shared_ptr<RessourcesLoader> &getResourceLoader() const;
		void setResourceLoader(const std::shared_ptr<RessourcesLoader> &_resourceLoader);
		void pushDataPacket(Packet::DataPacket *packet);
		void stop();
		std::unique_ptr<std::vector<std::unique_ptr<Packet::DataPacket>>>
		getPackets();
		Entity *cloneEntity(const std::string &name) const;

	private:
		std::thread _thread;
		std::unique_ptr<World> _world;
		EventList _eventList;
		PacketList _packetList;
		EnemyLoader _enemyLoader;
		std::unique_ptr<std::map<const std::string, Engine::Entity *>> _DLEntitiesMap;
		std::shared_ptr<RessourcesLoader> _resourceLoader;
		bool _stop;
	};
}

#endif //RTYPE_GAME_HPP
