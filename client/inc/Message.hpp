/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_MESSAGE_HPP_
# define RTYPE_MESSAGE_HPP_

# include "DataPacket.hpp"
# include "IMessage.hpp"
# include "PacketInterpreter.hpp"

class Message : public IMessage
{
public:
	explicit Message(const std::string &rawMessage) noexcept;
	Message(const Message &) noexcept;
	Message &operator=(const Message &) noexcept;
	~Message() = default;

	const std::string getRawMessage() const noexcept override;

private:
	const std::size_t 	PACKETSIZE = sizeof(DataPacket);

	std::string		_rawMessage;
	DataPacket		_packet;
	PacketInterpreter	_interpreter;

	void	transformStringToPacket(const std::string &str) noexcept;
};

#endif // !RTYPE_MESSAGE_HPP_