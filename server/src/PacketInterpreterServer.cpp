/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <iostream>
#include "PacketInterpreterServer.hpp"

PacketInterpreterServer::PacketInterpreterServer()
{
	fptr[CONNECT] = &PacketInterpreterServer::connect;
	fptr[DISCONNECT] = &PacketInterpreterServer::disconnect;
	fptr[CONNECTED] = &PacketInterpreterServer::connected;
	fptr[DISCONNECTED] = &PacketInterpreterServer::disconnected;
	fptr[STARTGAME] = &PacketInterpreterServer::startGame;
	fptr[READY] = &PacketInterpreterServer::ready;
	fptr[POSITION] = &PacketInterpreterServer::position;
	fptr[HIT] = &PacketInterpreterServer::hit;
	fptr[EVENT] = &PacketInterpreterServer::event;
}

void	PacketInterpreterServer::interpretPacket(const Packet::DataPacket &packet) noexcept
{
	std::cout << "CLIENT CMD = " << packet.cmd << std::endl;
	if (packet.cmd < UNKNOWN) {
		(this->*fptr[packet.cmd])(packet);
	}
}

void PacketInterpreterServer::connect(const Packet::DataPacket &packet) noexcept
{
	std::cout << "CONNECT" << std::endl;
}

void PacketInterpreterServer::disconnect(const Packet::DataPacket &packet) noexcept
{
	std::cout << "DISCONNECT" << std::endl;
}

void PacketInterpreterServer::connected(const Packet::DataPacket &packet) noexcept
{
	std::cout << "CONNECTED" << std::endl;
}

void PacketInterpreterServer::disconnected(const Packet::DataPacket &packet) noexcept
{
	std::cout << "DISCONNECTED" << std::endl;
}

void PacketInterpreterServer::startGame(const Packet::DataPacket &packet) noexcept
{
}

void PacketInterpreterServer::ready(const Packet::DataPacket &packet) noexcept
{
}

void PacketInterpreterServer::position(const Packet::DataPacket &packet) noexcept
{
}

void PacketInterpreterServer::hit(const Packet::DataPacket &packet) noexcept
{
}

void PacketInterpreterServer::event(const Packet::DataPacket &packet) noexcept
{
}
