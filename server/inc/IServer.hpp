//
// Created by Clément Péau on 10/01/2018.
//

#ifndef RTYPE_ISERVER_HPP
#define RTYPE_ISERVER_HPP
#include "AServer.hpp"

class IServer : public AServer {
public:
	
	virtual bool start() = 0;
	virtual bool stop() = 0;
	virtual bool sendMessage(const ClientObject &client, const IMessage
	&message) = 0;
	virtual bool tick() = 0;
};

#endif //RTYPE_ISERVER_HPP
