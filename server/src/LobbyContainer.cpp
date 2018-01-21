//
// Created by Clément Péau on 16/01/2018.
//

#include <vector>
#include <iostream>
#include <Message.hpp>
#include <Logger.hpp>
#include "LobbyContainer.hpp"

bool LobbyContainer::isClientContained(ClientObject &client)
{
	for (auto &t : _lobbyList) {
		if (t->isClientContained(client))
			return (true);
	}
	return (false);
}
std::unique_ptr<Lobby>::pointer LobbyContainer::getClientLobby(ClientObject
                                                           &client)
{
	for (auto &t : _lobbyList) {
		if (t->isClientContained(client))
			return (t.get());
	}
	throw std::out_of_range("No game containing client passed as "
		                        "parameter");
}

bool LobbyContainer::addClientToLobby(ClientObject &client,
                                      unsigned short seed) noexcept
{
	for (auto &t : _lobbyList) {
		if (t->isStarted() && !t->isFull() && t->getSeed() == seed) {
			t->addClient(client);
			return (true);
		}
	}
	std::unique_ptr<Lobby> lob = std::make_unique<Lobby>(seed);
	
	lob->addClient(client);
	_lobbyList.emplace_back(std::move(lob));
	return (true);
}

LobbyContainer::LobbyContainer()
{
}

LobbyContainer::~LobbyContainer()
{

}
void LobbyContainer::dump()
{
	int i = 0;
	
	for (auto &t : _lobbyList) {
		if (t->getSeed() == 0)
			std::cout << "There is " << t->size() << " in lobby "
				"" << i++ << " with no seed" << '\n';
		else
			std::cout << "There is " << t->size() << " in lobby "
		          << i++ << " with seed " << t->getSeed() << '\n';
	}
}
void LobbyContainer::checkTimeout()
{
	for (auto &t : _lobbyList) {
		t->checkTimeout();
	}
	_lobbyList.erase(std::find_if(_lobbyList.begin(), _lobbyList.end(),
				      [](const std::unique_ptr<Lobby> &lob) {
					      return (lob->size() == 0);
				      })
		, _lobbyList.end());
}

std::unique_ptr<std::vector<std::pair<std::unique_ptr<std::vector<std
::unique_ptr<Packet::DataPacket>>>, Lobby *>>> LobbyContainer::getPacketFromGames()
{
	auto v = std::make_unique<std::vector<std::pair<std::unique_ptr<std
	::vector<std::unique_ptr<Packet::DataPacket>>>, Lobby *>>>();
	for (auto &t : _lobbyList) {
		auto pair = std::make_pair(t->getPackets(), t.get());
		v->push_back(std::move(pair));
	}
	return (v);
}
