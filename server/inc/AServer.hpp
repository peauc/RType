/*
** EPITECH  PROJECT , 2020
** r-type
** File  description:
** 	No description
*/

#ifndef ASERVER_HPP
#define ASERVER_HPP
#include <vector>
#include "IClientObject.hpp"
#include "IMessage.hpp"
#include "ClientObjectManager.hpp"

class AServer {
public:
	AServer();
	
	virtual~AServer();
	virtual bool start();
	virtual bool stop();
	
	const ClientObjectManager &getClientManager();
	virtual std::vector<IMessage> getClientMessage(IClientObject &client);
private:
	ClientObjectManager _clientManager;
	bool _shouldStop = false;
};

#endif //ASERVER_HPP
