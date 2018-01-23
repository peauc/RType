//
// Created by Clément Péau on 13/01/2018.
//

#ifndef RTYPE_ICLIENT_HPP
#define RTYPE_ICLIENT_HPP
#include "string"

namespace client {
class IClient {
public:
	virtual bool sendMessage(const std::string &message) noexcept = 0;
	virtual bool connect(const std::string &message, const std::string
	&port, unsigned short seed)
	noexcept = 0;
	private:
};
}

#endif //RTYPE_ICLIENT_HPP
