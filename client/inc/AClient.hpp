//
// Created by Clément Péau on 13/01/2018.
//

#ifndef RTYPE_ACLIENT_HPP
#define RTYPE_ACLIENT_HPP

#include "IClient.hpp"

namespace client {
class AClient : IClient{
public:
	bool isConnected();
private:
	bool _connected;
};
}

#endif //RTYPE_ACLIENT_HPP
