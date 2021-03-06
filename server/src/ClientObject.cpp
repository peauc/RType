#include <Logger.hpp>
#include <Message.hpp>
#include "ClientObject.hpp"

ClientObject::ClientObject(boost::asio::ip::udp::endpoint &endpoint) :
	_endpoint(endpoint), _timeoutStart
	(std::chrono::steady_clock::now())
{
}

ClientObject::ClientObject() {}
const boost::asio::ip::udp::endpoint &ClientObject::getEndpoint() const
{
	return _endpoint;
}
bool ClientObject::operator==(const ClientObject &a) const noexcept
{
	return (a._endpoint == this->_endpoint);
}

long long int ClientObject::currentTimout() const noexcept
{
	return (std::chrono::duration_cast<std::chrono::seconds>
		(std::chrono::steady_clock::now() -
		 _timeoutStart).count());
}
bool ClientObject::isTimedOut(long long int timeoutValue) const noexcept
{
	if (timeoutValue <= currentTimout()) {
		Logger::Log(Logger::DEBUG, "Client has timed out, isTimedOut"
			" returning true");
	}
	return timeoutValue <= currentTimout();
}
void ClientObject::resetTimeout() noexcept
{
	_timeoutStart = std::chrono::steady_clock::now();
}

void ClientObject::toggleReady() noexcept
{
	_isReady = !_isReady;
}

bool ClientObject::isReady() const noexcept
{
	return (_isReady);
}

size_t ClientObject::getEntityID() const noexcept
{
	return (_entityID);
}

void ClientObject::setEntityID(size_t entityID) noexcept
{
	_entityID = entityID;
}
