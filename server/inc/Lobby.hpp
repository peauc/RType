//
// Created by Clément Péau on 15/01/2018.
//

#ifndef RTYPE_LOBBY_HPP
#define RTYPE_LOBBY_HPP

#include <boost/asio.hpp>
#include "Engine/Game.hpp"
#include "ClientObject.hpp"
#include "ClientObjectManager.hpp"

class Lobby {
public:
	Lobby();
	explicit Lobby(unsigned short seed);
	~Lobby();
	
	void checkTimeout() noexcept;
	bool addClient(ClientObject &client) noexcept;
	size_t size() const noexcept;
	bool isFull() const noexcept;
	bool isClientContained(const ClientObject &client) const noexcept;
	bool startGame();
	ClientObject &getClientContained(const ClientObject &copy);
	bool isSeededLobby() const noexcept;
	unsigned short getSeed() const noexcept;
private:
	bool _isSeededLobby;
	unsigned short _seed;
	Engine::Game _game;
	ClientObjectManager _clientManager;
};

#endif //RTYPE_LOBBY_HPP
