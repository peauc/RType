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
	fptr[Packet::CONNECT] = &PacketInterpreterClient::connect;
	fptr[Packet::DISCONNECT] = &PacketInterpreterClient::disconnect;
	fptr[Packet::CONNECTED] = &PacketInterpreterClient::connected;
	fptr[Packet::DISCONNECTED] = &PacketInterpreterClient::disconnected;
	fptr[Packet::STARTGAME] = &PacketInterpreterClient::startGame;
	fptr[Packet::READY] = &PacketInterpreterClient::ready;
	fptr[Packet::POSITION] = &PacketInterpreterClient::position;
	fptr[Packet::EVENT] = &PacketInterpreterClient::event;
}

void	PacketInterpreterClient::interpretPacket(const Packet::DataPacket &packet) noexcept
{
	std::cout << "SERVER CMD = " << packet.cmd << std::endl;
	if (packet.cmd < Packet::UNKNOWN) {
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

void PacketInterpreterClient::event(const Packet::DataPacket &packet) noexcept
{
}
