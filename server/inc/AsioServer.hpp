/*
** EPITECH  PROJECT , 2020
** r-type
** File  description:
** 	No description
*/

#include "IServer.hpp"

#ifndef ASIOSERVER_HPP
#define ASIOSERVER_HPP

class AsioServer : public IServer {
public:
	AsioServer();
	~AsioServer();
	
	virtual bool stop();
	virtual bool start();
private:
};

#endif //ASIOSERVER_HPP
