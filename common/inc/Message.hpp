/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_MESSAGE_HPP_
# define RTYPE_MESSAGE_HPP_
#include <string>
# include "DataPacket.hpp"
# include "IMessage.hpp"
# include "PacketInterpreterClient.hpp"

class Message : public IMessage
{
public:
	Message() = default;
	explicit Message(const std::string &rawMessage) noexcept;
	Message(const Message &) noexcept;
	Message(Packet::Commands commands) noexcept;
	Message(Packet::DataPacket &) noexcept;
	Message &operator=(const Message &) noexcept;
	~Message() = default;

	const Packet::DataPacket getPacket() const noexcept;
	Packet::DataPacket		getPacket() noexcept;
	const std::string	getRawMessage() const noexcept override;
private:
	std::string		_rawMessage;
	Packet::DataPacket		_packet;

	void	transformStringToPacket(const std::string &str) noexcept;
};

#endif // !RTYPE_MESSAGE_HPP_
