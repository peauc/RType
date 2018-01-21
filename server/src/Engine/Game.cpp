//
// Created by romain on 12/01/18.
//

#include <thread>
#include <chrono>
#include <iostream>
#include "Logger.hpp"
#include "Engine/Game.hpp"

Engine::Game::Game()
{
	this->_world = std::make_unique<World>();
}

void Engine::Game::run()
{
	Logger::Log(Logger::CRITICAL, "Game is starting");
	std::chrono::time_point<std::chrono::system_clock> previous = std::chrono::system_clock::now();
	long lag = 0;
	this->_stop = false;

	while (!this->_stop) {
		std::chrono::time_point<std::chrono::system_clock> current = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>
				(current - previous);
		previous = current;
		lag += elapsed.count();

		while (lag >= NS_PER_UPDATE) {
			this->_world->update();
			lag -= NS_PER_UPDATE;
		}
	}
}

void Engine::Game::setup(size_t nbOfPlayers,
						 const std::shared_ptr<RessourcesLoader> &resourceLoader)
{
	std::unique_ptr<Engine::World> world = std::make_unique<Engine::World>();

	this->setWorld(std::move(world));
	this->_world->addMediator();
	this->setResourceLoader(resourceLoader);
	std::unique_ptr<Engine::Entity> camera = std::unique_ptr<Engine::Entity>
			(Factory::EntityFactory::createCamera(0, *this));

	this->_world->setCamera(std::move(camera));

	for (unsigned int i = 0; i < nbOfPlayers; ++i) {
		this->_world->addObject(Factory::EntityFactory::createPlayerShip);
	}

	//this->_enemyLoader.setup("../DLEnemies/", *this);
	//this->_DLEntitiesMap = this->_enemyLoader.getEnemies();
}

std::unique_ptr<Engine::World> &Engine::Game::getWorld()
{
	return _world;
}

const std::unique_ptr<Engine::World> &Engine::Game::getWorld() const
{
	return _world;
}

void Engine::Game::setWorld(std::unique_ptr<World> world)
{
	if (this->_world != nullptr) {
		this->_world->setParentGame(nullptr);
	}
	this->_world = std::move(world);
	this->_world->setParentGame(this);
}

const std::shared_ptr<RessourcesLoader> &Engine::Game::getResourceLoader() const
{
	return _resourceLoader;
}

void Engine::Game::setResourceLoader(const std::shared_ptr<RessourcesLoader> &_resourceLoader)
{
	this->_resourceLoader = _resourceLoader;
}

Engine::EventList &Engine::Game::getEventList()
{
	return _eventList;
}

void Engine::Game::pushDataPacket(Packet::DataPacket *packet)
{
	this->_packetList.pushBack(std::unique_ptr<Packet::DataPacket>(packet));
}

void Engine::Game::start()
{
	_thread = std::thread(&Game::run, this);
	Logger::Log(Logger::INFO, "Started Game");
}

Engine::Game::~Game()
{
	if (_thread.joinable())
		_thread.join();
	Logger::Log(Logger::CRITICAL, "Deleting the game");\

}

void Engine::Game::stop()
{
	_stop = true;
}

std::unique_ptr<std::vector<std::unique_ptr<Packet::DataPacket>>>
Engine::Game::getPackets() {
	auto l = std::make_unique<std::vector<std::unique_ptr<Packet
	::DataPacket>>>();
	std::unique_ptr<Packet::DataPacket> packet;
	while ((packet = _packetList.popBack()) != nullptr) {
		l->push_back(std::move(packet));
	}
	return (l);
}

Engine::Entity *Engine::Game::cloneEntity(const std::string &name) const
{
	std::map<const std::string, Entity *>::const_iterator ent = this->_DLEntitiesMap->find(name);
	if (ent != this->_DLEntitiesMap->end()) {
		return ent->second->clone();
	}
	return nullptr;
}
