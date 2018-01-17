//
// Created by Clément Péau on 16/01/2018.
//

#include "LobbyContainer.hpp"

bool LobbyContainer::isClientContained(ClientObject &client)
{
	for (auto &t : _lobbyList) {
		if (t.get()->isClientContained(client))
			return (true);
	}
	return (false);
}
std::unique_ptr<Lobby> &LobbyContainer::getClientLobby(ClientObject &client)
{
	for (auto &t : _lobbyList) {
		if (t.get()->isClientContained(client))
			return (t);
	}
	throw std::out_of_range("No game containing client passed as "
		                        "parameter");
}
bool LobbyContainer::addClientToLobby(ClientObject &client)
{
	for (auto &t : _lobbyList) {
		if (!t.get()->isFull()) {
			t.get()->addClient(client);
			return (true);
		}
	}
	std::unique_ptr<Lobby> lob(new Lobby());
	lob.get()->addClient(client);
	_lobbyList.emplace_back(std::move(lob));
	return (true);
}

LobbyContainer::LobbyContainer()
{
}

LobbyContainer::~LobbyContainer()
{
}
