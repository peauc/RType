//
// Created by Clément Péau on 11/01/2018.
//

#ifndef RTYPE_MESSAGE_HPP
#define RTYPE_MESSAGE_HPP

class IMessage {
public:
	virtual const std::string getRawMessage() const = 0;
private:
};

#endif //RTYPE_MESSAGE_HPP
