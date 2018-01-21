//
// Created by Clément Péau on 13/01/2018.
//

#include "AClient.hpp"

bool client::AClient::isConnected()
{
	return (_connected);
}
long long int client::AClient::getChronoElapsed()
{
	return (std::chrono::duration_cast<std::chrono::seconds>
		(std::chrono::steady_clock::now() -
		 _timeoutStart).count());
}

void client::AClient::resetChrono()
{
	_timeoutStart = std::chrono::steady_clock::now();
}
client::AClient::AClient() : _connected(false)
{
}
