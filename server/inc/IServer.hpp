//
// Created by Clément Péau on 10/01/2018.
//

#include "AServer.hpp"
#include <boost/asio.hpp>
#ifndef RTYPE_ISERVER_HPP
#define RTYPE_ISERVER_HPP

class IServer : public AServer {
public:
	IServer();
	~IServer();
	
	boost::asio::ip::udp::endpoint toto;
	
	enum IPVersion {
		defaultVersion = 0,
		v4,
		v6,
	};
private:


};

#endif //RTYPE_ISERVER_HPP
