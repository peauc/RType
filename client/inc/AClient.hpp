//
// Created by Clément Péau on 13/01/2018.
//

#ifndef RTYPE_ACLIENT_HPP
#define RTYPE_ACLIENT_HPP
#include <chrono>
#include "IClient.hpp"

namespace client {
class AClient : public IClient{
public:
	AClient();
	bool isConnected();
	long long int getChronoElapsed();
	void resetChrono();
private:
	std::chrono::steady_clock::time_point _timeoutStart;
	bool _connected;
};
}

#endif //RTYPE_ACLIENT_HPP
