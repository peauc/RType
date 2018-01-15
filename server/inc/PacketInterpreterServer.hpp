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
	void (PacketInterpreterServer::*fptr[UNKNOWN])(const DataPacket &packet);
};

#endif // !RTYPE_PACKETINTERPRETERSERVER_HPP_