//
// Created by Clément Péau on 10/01/2018.
//

#include "AServer.hpp"

#ifndef RTYPE_ISERVER_HPP
#define RTYPE_ISERVER_HPP

class IServer : public AServer {
public:
	IServer();
	~IServer();
	
	enum IPVersion {
		defaultVersion = 0,
		v4,
		v6,
	};
private:


};

#endif //RTYPE_ISERVER_HPP
