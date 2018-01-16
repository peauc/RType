/*
** EPITECH  PROJECT , 2020
** r-type
** File  description:
** 	No description
*/

#ifndef ASERVER_HPP
#define ASERVER_HPP
#include <vector>
#include "IMessage.hpp"
#include "ClientObjectManager.hpp"

class AServer {
public:
	AServer();
	
	virtual~AServer();
	virtual bool start();
	virtual bool stop();
	
	ClientObjectManager &getClientManager();
private:
	ClientObjectManager _clientManager;
	bool _shouldStop = false;
};

#endif //ASERVER_HPP
