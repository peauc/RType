//
// Created by Clément Péau on 10/01/2018.
//

#include "ClientManager.hpp"

size_t ClientManager::size() const
{
	return (_clientList.size());
}
std::vector<IMessage> ClientManager::getClientsMessages()
{
	std::vector<IMessage> messageList;
	//Todo:: Finish client
	for (auto i = 0; i < _clientList.size(); i++)
	{}
	return (messageList);
}
