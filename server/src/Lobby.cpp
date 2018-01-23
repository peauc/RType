//
// Created by Clément Péau on 15/01/2018.
//

#include <iostream>
#include <thread>
#include "Logger.hpp"
#include "Lobby.hpp"
#include "ResourcesLoader.hpp"

bool Lobby::isClientContained(const ClientObject &client) const noexcept
{
	return (_clientManager.isClientContained(client));
}

bool Lobby::isFull() const noexcept
{
	return (_clientManager.isFull());
}

bool Lobby::addClient(ClientObject &client) noexcept
{
	_clientManager.addClient(client);
	return (true);
}



Lobby::Lobby(unsigned short seed)
{
	_seed = seed;
	_isSeededLobby = true;
	_isStarted = false;
}

Lobby::~Lobby()
{
	Logger::Log(Logger::CRITICAL, "Deleting a lobby");
	_game.stop();
}

size_t Lobby::size() const noexcept
{
	return (_clientManager.size());
}
bool Lobby::isSeededLobby() const noexcept
{
	return (_isSeededLobby != 0);
}

unsigned short Lobby::getSeed() const noexcept
{
	return (_seed);
}
void Lobby::checkTimeout() noexcept
{
	_clientManager.checkClientsTimeout();
}

ClientObject &Lobby::getClientContained(const ClientObject &copy)
{
	return (_clientManager.getClientContained(copy));
}
bool Lobby::startGame()
{
	_game.start();
	_isStarted = true;
	auto e = std::make_shared<ResourcesLoader>();
	e->loadAnimations("../AssetsId.txt");
	_game.setup(_clientManager.size(), e);
	Logger::Log(Logger::CRITICAL, std::to_string(this->_game.getWorld()->getObjects().size()));
	for (auto &t : this->_game.getWorld()->getObjects()) {
		Logger::Log(Logger::DEBUG , std::to_string(t->getId()));
	}
	return (true);
}
const std::vector<ClientObject> &Lobby::getClientList()
{
	return (_clientManager.getClientList());
}
bool Lobby::isReady() const noexcept
{
	return (_clientManager.isReady());
}
bool Lobby::isStarted() const noexcept
{
	return (_isStarted);
}

void Lobby::pushEventInList(std::unique_ptr<Engine::Event> &event) noexcept
{
	_game.getEventList().pushBack(std::move(event));
}

std::unique_ptr<std::vector<std::unique_ptr<Packet::DataPacket>>>
Lobby::getPackets() {
	return (_game.getPackets());
}
bool Lobby::removeClient(const ClientObject &obj) noexcept
{
	return _clientManager.removeClient(obj);
}


