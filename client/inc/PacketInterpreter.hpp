/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_PACKETINTERPRETER_HPP_
# define RTYPE_PACKETINTERPRETER_HPP_

# include "DataPacket.hpp"

class	PacketInterpreter
{
public:
	PacketInterpreter();
	PacketInterpreter(const PacketInterpreter &) = default;
	PacketInterpreter &operator=(const PacketInterpreter &) = default;
	~PacketInterpreter() = default;
	
	void	interpretPacket(const DataPacket &packet) noexcept;

private:
	enum Commands
	{
		CONNECT		= 0,
		DISCONNECT	= 1,
		CONNECTED	= 2,
		DISCONNECTED	= 3,
		STARTGAME	= 4,
		READY		= 5,
		POSITION	= 6,
		HIT		= 7,
		EVENT		= 8,
		UNKNOWN		= 9
	};
	
	void (PacketInterpreter::*fptr[UNKNOWN])(const DataPacket &packet);
	
	void	connect(const DataPacket &packet) noexcept;
	void	disconnect(const DataPacket &packet) noexcept;
	void	connected(const DataPacket &packet) noexcept;
	void	disconnected(const DataPacket &packet) noexcept;
	void	startGame(const DataPacket &packet) noexcept;
	void	ready(const DataPacket &packet) noexcept;
	void	position(const DataPacket &packet) noexcept;
	void	hit(const DataPacket &packet) noexcept;
	void	event(const DataPacket &packet) noexcept;
};

#endif // !RTYPE_PACKETINTERPRETER_HPP_