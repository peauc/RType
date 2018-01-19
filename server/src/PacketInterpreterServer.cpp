/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include <iostream>
#include <Logger.hpp>
#include "PacketInterpreterServer.hpp"

PacketInterpreterServer::PacketInterpreterServer()
{
	fptr[Packet::CONNECT] = &PacketInterpreterServer::connect;
	fptr[Packet::DISCONNECT] = &PacketInterpreterServer::disconnect;
	fptr[Packet::CONNECTED] = &PacketInterpreterServer::connected;
	fptr[Packet::DISCONNECTED] = &PacketInterpreterServer::disconnected;
	fptr[Packet::STARTGAME] = &PacketInterpreterServer::startGame;
	fptr[Packet::READY] = &PacketInterpreterServer::ready;
	fptr[Packet::POSITION] = &PacketInterpreterServer::position;
	fptr[Packet::HIT] = &PacketInterpreterServer::hit;
	fptr[Packet::EVENT] = &PacketInterpreterServer::event;
	fptr[Packet::PONG] = &PacketInterpreterServer::pong;
}

void	PacketInterpreterServer::interpretPacket(const Packet::DataPacket &packet) noexcept
{
	if (packet.cmd < Packet::UNKNOWN) {
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
void PacketInterpreterServer::pong(const Packet::DataPacket &packet)
{
	Logger::Log(Logger::DEBUG, "Client Ponged the server");
}

Engine::Event PacketInterpreterServer::createEventFromPacket(const Packet::DataPacket
							     &packet,
							     uint32_t id) noexcept
{
	Engine::Event event(id);
	
	event._yVelocity = packet.data.input.yVelocity;
	event._xVelocity = packet.data.input.xVelocity;
	event._chargingShot = packet.data.input.charged;
	event._shotReleased = packet.data.input.shot;
	return (event);
}
