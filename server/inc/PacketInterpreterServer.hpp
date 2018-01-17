/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_PACKETINTERPRETERSERVER_HPP_
# define RTYPE_PACKETINTERPRETERSERVER_HPP_

# include "IPacketInterpreter.hpp"

class	PacketInterpreterServer : public IPacketInterpreter
{
public:
	PacketInterpreterServer();
	PacketInterpreterServer(const PacketInterpreterServer &) = delete;
	PacketInterpreterServer &operator=(const PacketInterpreterServer &)
	= delete;
	~PacketInterpreterServer() override = default;
	
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
	void (PacketInterpreterServer::*fptr[UNKNOWN])(const Packet::DataPacket &packet);
};

#endif // !RTYPE_PACKETINTERPRETERSERVER_HPP_
