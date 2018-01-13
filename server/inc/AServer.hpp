/*
** EPITECH  PROJECT , 2020
** r-type
** File  description:
** 	No description
*/

#ifndef ASERVER_HPP
#define ASERVER_HPP
#include <vector>
#include "IClient.hpp"
#include "IMessage.hpp"
#include "ClientManager.hpp"

class AServer {
public:
	AServer();
	
	virtual~AServer();
	virtual bool start();
	virtual bool stop();
	
	const ClientManager &getClientManager();
	virtual std::vector<IMessage> getClientMessage(IClient &client);
private:
	ClientManager _clientManager;
	bool _shouldStop = false;
};

#endif //ASERVER_HPP
