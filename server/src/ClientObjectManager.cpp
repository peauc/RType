//
// Created by Clément Péau on 10/01/2018.
//

#include <iostream>
#include <chrono>
#include <Logger.hpp>
#include "ClientObjectManager.hpp"

size_t ClientObjectManager::size() const
{
	return (_clientList.size());
}

std::vector<IMessage> ClientObjectManager::getClientsMessages()
{
	std::vector<IMessage> messageList;
	//Todo:: Finish client
	for (size_t i = 0; i < _clientList.size(); i++)
	{}
	return (messageList);
}

bool ClientObjectManager::addClient(ClientObject &obj) noexcept
{
	if (size() >= 4)
		return (false);
	obj.setEntityID(size());
	_clientList.push_back(obj);
	return (true);
}

bool ClientObjectManager::isClientContained(const ClientObject &client) const
noexcept
{
	return (!(std::find(_clientList.begin(), _clientList.end(), client) ==
	         _clientList.end()));
}

void ClientObjectManager::checkClientsTimeout() noexcept
{
	_clientList.erase(std::remove_if(_clientList.begin(), _clientList
		                                 .end(),
	                       [](ClientObject &obj) {
		                       return (obj.isTimedOut(15));
	                       }
	), _clientList.end());
}

void ClientObjectManager::setMaxTimeoutTime(
		std::chrono::steady_clock::time_point &time) noexcept
{
	_maxTimeoutTimerStart = time;
}

bool ClientObjectManager::isFull() const noexcept
{
	return (size() >= _maxSize);
}

void ClientObjectManager::setMaxSize(size_t size) noexcept
{
	_maxSize = size;
}

ClientObjectManager::ClientObjectManager()
{
	_maxSize = 4;
}
ClientObject &
ClientObjectManager::getClientContained(const ClientObject &copy)
{
	for (auto &t : _clientList) {
		if (t == copy)
			return (t);
	}
	throw std::out_of_range("Specific client is not contained in this "
		                        "Manager");
}
const std::vector<ClientObject> &ClientObjectManager::getClientList()
{
	return (_clientList);
}
bool ClientObjectManager::isReady() const noexcept
{
	for (auto it = _clientList.begin(); it < _clientList.end(); it++) {
		std::cout << "Client " << it.operator*().getEntityID() << " " << it.operator*().isReady() << std::endl;
		if (!it->isReady())
			return (false);
	}
	return (true);
}
bool ClientObjectManager::removeClient(const ClientObject &client) noexcept
{
	auto e = std::find_if(_clientList.begin(), _clientList.end(),
		     [client](const ClientObject &client_) {
			     return (client == client_);
		     });
	if (e == _clientList.end()) {
		return (false);
	}
	_clientList.erase(e, _clientList.end());
	return (true);
}
