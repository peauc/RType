//
// Created by Clément Péau on 16/01/2018.
//

#include "LobbyContainer.hpp"

bool LobbyContainer::isClientContained(ClientObject &client)
{
	for (auto &t : _lobbyList) {
		if (t.isClientContained(client))
			return (true);
	}
	return (false);
}
Lobby &LobbyContainer::getClientLobby(ClientObject &client)
{
	for (auto &t : _lobbyList) {
		if (t.isClientContained(client))
			return (t);
	}
	throw std::out_of_range("No game containing client passed as "
		                        "parameter");
}
bool LobbyContainer::addClientToLobby(ClientObject &client)
{
	for (auto &t : _lobbyList) {
		if (!t.isFull()) {
			t.addClient(client);
			return (true);
		}
	}
	Lobby lob;
	lob.addClient(client);
	_lobbyList.push_back(lob);
	return (true);
}
