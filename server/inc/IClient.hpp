//
// Created by Clément Péau on 11/01/2018.
//

#ifndef RTYPE_ICLIENT_HPP
#define RTYPE_ICLIENT_HPP

#include <string>
#include "IMessage.hpp"

class IClient {
public:
	virtual bool hasDataToBeRead(const IClient &client) const = 0;
	virtual bool sendMessage(const IMessage &message) const = 0;
	virtual std::vector<IMessage> &getMessages() const = 0;
	
private:
};

#endif //RTYPE_ICLIENT_HPP
