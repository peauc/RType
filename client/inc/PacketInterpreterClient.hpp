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

	void	interpretPacket(const DataPacket &packet) noexcept override;
	void	connect(const DataPacket &packet) noexcept override;
	void	disconnect(const DataPacket &packet) noexcept override;
	void	connected(const DataPacket &packet) noexcept override;
	void	disconnected(const DataPacket &packet) noexcept override;
	void	startGame(const DataPacket &packet) noexcept override;
	void	ready(const DataPacket &packet) noexcept override;
	void	position(const DataPacket &packet) noexcept override;
	void	hit(const DataPacket &packet) noexcept override;
	void	event(const DataPacket &packet) noexcept override;

private:
	void (PacketInterpreterClient::*fptr[UNKNOWN])(const DataPacket &packet);
};

#endif // !RTYPE_PACKETINTERPRETERCLIENT_HPP_