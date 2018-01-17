/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <iostream>
#include "PacketInterpreterClient.hpp"

PacketInterpreterClient::PacketInterpreterClient()
{
	fptr[CONNECT] = &PacketInterpreterClient::connect;
	fptr[DISCONNECT] = &PacketInterpreterClient::disconnect;
	fptr[CONNECTED] = &PacketInterpreterClient::connected;
	fptr[DISCONNECTED] = &PacketInterpreterClient::disconnected;
	fptr[STARTGAME] = &PacketInterpreterClient::startGame;
	fptr[READY] = &PacketInterpreterClient::ready;
	fptr[POSITION] = &PacketInterpreterClient::position;
	fptr[HIT] = &PacketInterpreterClient::hit;
	fptr[EVENT] = &PacketInterpreterClient::event;
}

void	PacketInterpreterClient::interpretPacket(const Packet::DataPacket &packet) noexcept
{
	std::cout << "SERVER CMD = " << packet.cmd << std::endl;
	if (packet.cmd < UNKNOWN) {
		(this->*fptr[packet.cmd])(packet);
	}
}

void PacketInterpreterClient::connect(const Packet::DataPacket &packet) noexcept
{
	std::cout << "CONNECT" << std::endl;
}

void PacketInterpreterClient::disconnect(const Packet::DataPacket &packet) noexcept
{
	std::cout << "DISCONNECT" << std::endl;
}

void PacketInterpreterClient::connected(const Packet::DataPacket &packet) noexcept
{
	std::cout << "CONNECTED" << std::endl;
}

void PacketInterpreterClient::disconnected(const Packet::DataPacket &packet) noexcept
{
	std::cout << "DISCONNECTED" << std::endl;
}

void PacketInterpreterClient::startGame(const Packet::DataPacket &packet) noexcept
{
}

void PacketInterpreterClient::ready(const Packet::DataPacket &packet) noexcept
{
}

void PacketInterpreterClient::position(const Packet::DataPacket &packet) noexcept
{
}

void PacketInterpreterClient::hit(const Packet::DataPacket &packet) noexcept
{
}

void PacketInterpreterClient::event(const Packet::DataPacket &packet) noexcept
{
}
