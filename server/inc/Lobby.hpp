//
// Created by Clément Péau on 15/01/2018.
//

#ifndef RTYPE_LOBBY_HPP
#define RTYPE_LOBBY_HPP

#include <boost/asio.hpp>
#include "Engine/Game.hpp"
#include "ClientObject.hpp"

class Lobby {
public:
	Lobby();
	~Lobby();
	
	bool addClient(ClientObject &client) noexcept;
	size_t size() const noexcept ;
	bool isFull() const noexcept ;
	bool isClientContained(const ClientObject &client) const noexcept ;
private:
	Engine::Game _game;
	std::vector<ClientObject> _clientList;
};

#endif //RTYPE_LOBBY_HPP
