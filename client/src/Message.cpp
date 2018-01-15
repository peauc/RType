/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <cstring>
#include "Message.hpp"

Message::Message(const std::string &rawMessage) noexcept
 : _rawMessage(rawMessage)
{
	this->transformStringToPacket(rawMessage);
	this->_interpreter.interpretPacket(this->_packet);
}

Message::Message(const Message &other) noexcept
 : _rawMessage(other._rawMessage)
{
	if (this != &other) {
		this->_rawMessage = other._rawMessage;
		this->_packet = other._packet;
		this->_interpreter = other._interpreter;
	}
}

Message &Message::operator=(const Message &other) noexcept
{
	if (this != &other) {
		this->_rawMessage = other._rawMessage;
		this->_packet = other._packet;
		this->_interpreter = other._interpreter;
	}
	return (*this);
}

void	Message::transformStringToPacket(const std::string &str) noexcept
{
	std::memcpy(&this->_packet,
		    this->_rawMessage.c_str(),
		    Message::PACKETSIZE);
}

const std::string Message::getRawMessage() const noexcept
{
	return (this->_rawMessage);
}
