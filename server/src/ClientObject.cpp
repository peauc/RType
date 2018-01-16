#include "ClientObject.hpp"

ClientObject::ClientObject(boost::asio::ip::udp::endpoint &endpoint) :
	_endpoint(endpoint)
{
}

ClientObject::ClientObject() {}
