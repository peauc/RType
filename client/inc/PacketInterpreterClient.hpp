/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_PACKETINTERPRETERCLIENT_HPP_
# define RTYPE_PACKETINTERPRETERCLIENT_HPP_

# include "IPacketInterpreter.hpp"

class	PacketInterpreterClient : public IPacketInterpreter
{
public:
	PacketInterpreterClient();
	PacketInterpreterClient(const PacketInterpreterClient &) = delete;
	PacketInterpreterClient &operator=(const PacketInterpreterClient &) = delete;
	~PacketInterpreterClient() override = default;

	void	interpretPacket(const Packet::DataPacket &packet) noexcept override;
	void	connect(const Packet::DataPacket &packet) noexcept override;
	void	disconnect(const Packet::DataPacket &packet) noexcept override;
	void	connected(const Packet::DataPacket &packet) noexcept override;
	void	disconnected(const Packet::DataPacket &packet) noexcept override;
	void	startGame(const Packet::DataPacket &packet) noexcept override;
	void	ready(const Packet::DataPacket &packet) noexcept override;
	void	position(const Packet::DataPacket &packet) noexcept override;
	void	hit(const Packet::DataPacket &packet) noexcept override;
	void	event(const Packet::DataPacket &packet) noexcept override;

private:
	void (PacketInterpreterClient::*fptr[UNKNOWN])(const Packet::DataPacket &packet);
};

#endif // !RTYPE_PACKETINTERPRETERCLIENT_HPP_
