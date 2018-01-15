/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <iostream>
#include "PacketInterpreter.hpp"

PacketInterpreter::PacketInterpreter()
{
	fptr[CONNECT] = &PacketInterpreter::connect;
	fptr[DISCONNECT] = &PacketInterpreter::disconnect;
	fptr[CONNECTED] = &PacketInterpreter::connected;
	fptr[DISCONNECTED] = &PacketInterpreter::disconnected;
	fptr[STARTGAME] = &PacketInterpreter::startGame;
	fptr[READY] = &PacketInterpreter::ready;
	fptr[POSITION] = &PacketInterpreter::position;
	fptr[HIT] = &PacketInterpreter::hit;
	fptr[EVENT] = &PacketInterpreter::event;
}

void	PacketInterpreter::interpretPacket(const DataPacket &packet) noexcept
{
	std::cout << "CMD = " << packet.cmd << std::endl;
	if (packet.cmd < UNKNOWN) {
		(this->*fptr[packet.cmd])(packet);
	}
}

void PacketInterpreter::connect(const DataPacket &packet) noexcept
{
	std::cout << "CONNECT" << std::endl;
}

void PacketInterpreter::disconnect(const DataPacket &packet) noexcept
{
	std::cout << "DISCONNECT" << std::endl;
}

void PacketInterpreter::connected(const DataPacket &packet) noexcept
{
	std::cout << "CONNECTED" << std::endl;
}

void PacketInterpreter::disconnected(const DataPacket &packet) noexcept
{
	std::cout << "DISCONNECTED" << std::endl;
}

void PacketInterpreter::startGame(const DataPacket &packet) noexcept
{
}

void PacketInterpreter::ready(const DataPacket &packet) noexcept
{
}

void PacketInterpreter::position(const DataPacket &packet) noexcept
{
}

void PacketInterpreter::hit(const DataPacket &packet) noexcept
{
}

void PacketInterpreter::event(const DataPacket &packet) noexcept
{
}
