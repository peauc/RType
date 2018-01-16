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
	explicit Message(const std::string &rawMessage) noexcept;
	Message(const Message &) noexcept;
	Message &operator=(const Message &) noexcept;
	~Message() = default;

	DataPacket		getPacket() const noexcept;
	const std::string	getRawMessage() const noexcept override;
private:
	std::string		_rawMessage;
	DataPacket		_packet;

	void	transformStringToPacket(const std::string &str) noexcept;
};

#endif // !RTYPE_MESSAGE_HPP_