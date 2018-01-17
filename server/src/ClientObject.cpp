#include "ClientObject.hpp"

ClientObject::ClientObject(boost::asio::ip::udp::endpoint &endpoint) :
	_endpoint(endpoint)
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
