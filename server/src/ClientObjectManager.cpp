//
// Created by Clément Péau on 10/01/2018.
//

#include "ClientObjectManager.hpp"

size_t ClientObjectManager::size() const
{
	return (_clientList.size());
}
std::vector<IMessage> ClientObjectManager::getClientsMessages()
{
	std::vector<IMessage> messageList;
	//Todo:: Finish client
	for (auto i = 0; i < _clientList.size(); i++)
	{}
	return (messageList);
}
bool ClientObjectManager::addClient(ClientObject &obj) noexcept
{
	if (size() >= 4)
		return (false);
	_clientList.push_back(obj);
	return (true);
}
bool ClientObjectManager::isClientContained(ClientObject &client) noexcept
{
	return !(std::find(_clientList.begin(), _clientList.end(), client) ==
	         _clientList.end());
}
