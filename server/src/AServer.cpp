//
// Created by Clément Péau on 11/01/2018.
//

#include "ClientObjectManager.hpp"
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

ClientObjectManager &AServer::getClientManager()
{
	return (_clientManager);
}

AServer::~AServer()
{

}
