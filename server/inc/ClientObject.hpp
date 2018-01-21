//
// Created by Clément Péau on 10/01/2018.
//

#ifndef RTYPE_CLIENTOBJECT_HPP
#define RTYPE_CLIENTOBJECT_HPP
#include <boost/array.hpp>
#include <boost/asio/ip/udp.hpp>
#include <chrono>
#include <DataPacket.hpp>

class ClientObject {
public:
	explicit ClientObject(boost::asio::ip::udp::endpoint &endpoint);
	const boost::asio::ip::udp::endpoint &getEndpoint() const;
	bool operator==(const ClientObject &a) const noexcept;
	long long int currentTimout() const noexcept;
	bool isTimedOut(long long int timeoutValue) const noexcept;
	void resetTimeout() noexcept;
	void toggleReady() noexcept;
	bool isReady() const noexcept;
	unsigned int getEntityID() const noexcept;
	void setEntityID(unsigned int) noexcept;
private:
	ClientObject();
	bool _isReady;
	boost::asio::ip::udp::endpoint _endpoint;
	std::chrono::steady_clock::time_point _timeoutStart;
	std::chrono::steady_clock::duration _maxTimout;
	unsigned int	_entityID;
};


#endif //RTYPE_CLIENTOBJECT_HPP
