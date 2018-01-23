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
	
	void checkTimeout();
	bool isClientContained(ClientObject &client);
	std::unique_ptr<Lobby>::pointer getClientLobby(const ClientObject
						       &client);
	bool addClientToLobby(ClientObject &client, unsigned short seed) noexcept;
	void dump();
	void removeClient(const ClientObject &client);
	std::unique_ptr<std::vector<std::pair<std::unique_ptr<std::vector<std
	::unique_ptr<Packet::DataPacket>>>, Lobby *>>> getPacketFromGames();
private:
	std::vector<std::unique_ptr<Lobby> > _lobbyList;
	void removeEmptyLobbies();
};

#endif //RTYPE_LOBBYCONTAINER_HPP
