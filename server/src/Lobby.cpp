//
// Created by Clément Péau on 15/01/2018.
//

#include <iostream>
#include <thread>
#include "Lobby.hpp"

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

Lobby::Lobby()
{
}

Lobby::~Lobby()
{
}

size_t Lobby::size() const noexcept
{
	return (_clientManager.size());
}
bool Lobby::isSeededLobby() const noexcept
{
	return (_isSeededLobby);
}

Lobby::Lobby(unsigned short seed)
{
	_seed = seed;
	_isSeededLobby = true;
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
	_game.run();
	return (true);
}


