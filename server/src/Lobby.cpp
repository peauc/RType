//
// Created by Clément Péau on 15/01/2018.
//

#include "Lobby.hpp"

bool Lobby::isClientContained(const ClientObject &client) const noexcept
{
	for (auto &t : _clientList) {
		if (t == client)
			return (true);
	}
	return (false);
}

bool Lobby::isFull() const noexcept
{
	return (_clientList.size() >= 4);
}

bool Lobby::addClient(ClientObject &client) noexcept
{
	_clientList.push_back(client);
	return (true);
}

Lobby::Lobby()
{
}

Lobby::~Lobby()
{
}


