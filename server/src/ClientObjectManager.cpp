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
