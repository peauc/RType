//
// Created by Clément Péau on 16/01/2018.
//

#ifndef RTYPE_LOBBYCONTAINER_HPP
#define RTYPE_LOBBYCONTAINER_HPP

#include "Lobby.hpp"
#include "ClientObject.hpp"

class LobbyContainer {
public:
	LobbyContainer();
	~LobbyContainer();
	bool isClientContained(ClientObject &client);
	std::unique_ptr<Lobby> &getClientLobby(ClientObject &client);
	bool addClientToLobby(ClientObject &client);
private:
	std::vector<std::unique_ptr<Lobby> > _lobbyList;
};

#endif //RTYPE_LOBBYCONTAINER_HPP
