//
// Created by Clément Péau on 11/01/2018.
//

#include "AServer.hpp"

bool AServer::stop()
{
	_shouldStop = true;
	return (true);
}

AServer::AServer()
{
	start();
}
bool AServer::start()
{
	_shouldStop = false;
	return (true);
}
const ClientManager &AServer::getClientManager()
{
	return (_clientManager);
}

std::vector<IMessage> AServer::getClientMessage(IClient &client)
{
	return (_clientManager.getClientsMessages());
}

AServer::~AServer()
{

}