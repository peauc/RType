//
// Created by Clément Péau on 10/01/2018.
//

#ifndef RTYPE_CLIENT_HPP
#define RTYPE_CLIENT_HPP
#include <boost/array.hpp>
#include <boost/asio/ip/udp.hpp>
#include "ClientObject.hpp"

class ClientObject {
public:
	explicit ClientObject(boost::asio::ip::udp::endpoint &endpoint);
private:
	ClientObject();
	boost::array<char, 65245> _buffer;
	boost::asio::ip::udp::endpoint _endpoint;
};

bool operator==(const ClientObject &a, const ClientObject &b) {
	return (a._endpoint == b._endpoint);
}

#endif //RTYPE_CLIENT_HPP
