/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_IPACKETINTERPRETER_HPP
# define RTYPE_IPACKETINTERPRETER_HPP

# include "DataPacket.hpp"

class	IPacketInterpreter
{
public:
	virtual ~IPacketInterpreter() = default;
	virtual void	interpretPacket(const DataPacket &packet) = 0;
	virtual void	connect(const DataPacket &packet) = 0;
	virtual void	disconnect(const DataPacket &packet) = 0;
	virtual void	connected(const DataPacket &packet) = 0;
	virtual void	disconnected(const DataPacket &packet) = 0;
	virtual void	startGame(const DataPacket &packet) = 0;
	virtual void	ready(const DataPacket &packet) = 0;
	virtual void	position(const DataPacket &packet) = 0;
	virtual void	hit(const DataPacket &packet) = 0;
	virtual void	event(const DataPacket &packet) = 0;

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
};

#endif //RTYPE_IPACKETINTERPRETER_HPP
