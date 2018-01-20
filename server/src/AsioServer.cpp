//
// Created by Clément Péau on 10/01/2018.
//

#include <boost/functional.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include "Logger.hpp"
#include "Message.hpp"
#include "AsioServer.hpp"

bool AsioServer::start()
{
	startReceive();
	return (true);
}

bool AsioServer::stop()
{
	return (false);
}

AsioServer::~AsioServer()
{
}

AsioServer::AsioServer() : _endpoint(boost::asio::ip::udp::v4(), 4242) ,
                           _socket
	(_ioService, _endpoint)
{
	fptr[Packet::CONNECT] = &AsioServer::connect;
	fptr[Packet::DISCONNECT] = &AsioServer::disconnect;
	fptr[Packet::CONNECTED] = &AsioServer::connected;
	fptr[Packet::DISCONNECTED] = &AsioServer::disconnected;
	fptr[Packet::STARTGAME] = &AsioServer::startGame;
	fptr[Packet::READY] = &AsioServer::ready;
	fptr[Packet::POSITION] = &AsioServer::position;
	fptr[Packet::HIT] = &AsioServer::hit;
	fptr[Packet::EVENT] = &AsioServer::event;
	fptr[Packet::PONG] = &AsioServer::pong;
	
}

bool AsioServer::sendMessage(const ClientObject &client, const IMessage
&message)
{
	boost::shared_ptr<std::string> toot(new std::string("toto"));
	
	_socket.async_send_to(boost::asio::buffer(*toot),
	                      _endpoint,
	                      boost::bind(&AsioServer::handleSend,
	                                  this, toot,
	                                  boost::asio::placeholders::error,
	                                  boost::asio::placeholders::bytes_transferred));
	return (true);
}

void AsioServer::handleSend(boost::shared_ptr<std::string> message,
                            const boost::system::error_code &error,
                            std::size_t bytesTransfered)
{
	Logger::Log(Logger::DEBUG, "Sent " + std::to_string(bytesTransfered));
}

void AsioServer::startReceive()
{
	_socket.async_receive_from(boost::asio::buffer(_array), _dummy_endpoint,
		boost::bind(&AsioServer::handleReceive, this,
		            boost::asio::placeholders::error,
		            boost::asio::placeholders::bytes_transferred));
}

void AsioServer::handleReceive(const boost::system::error_code &error,
                               std::size_t received)
{
	startReceive();
	if (received != Packet::PACKETSIZE)
		return ;
	Message message(std::string(_array.begin(), _array.end()));
	ClientObject tmp(_dummy_endpoint);
	Lobby *t;
	
	if (_lobbyList.isClientContained(tmp)) {
		t = _lobbyList.getClientLobby(tmp);
		try {
			t->getClientContained(tmp).resetTimeout();
		} catch (std::out_of_range &e) {
			Logger::Log(Logger::CRITICAL, e.what());
		}
		interpretPacket(message.getPacket(), t->getClientContained
							      (tmp));
	}
	else {
		Logger::Log(Logger::DEBUG, "New client");
		if (message.getPacket().cmd == Packet::CONNECT) {
			_lobbyList.addClientToLobby(tmp, message.getPacket()
			                                        .data
			                                        .connection
			                                        .seed);
			sendMessage(tmp, Message(Packet::CONNECTED));
		}
	}
	_lobbyList.dump();
}

bool AsioServer::tick()
{
	_ioService.poll();
	_ioService.reset();
	_lobbyList.checkTimeout();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	return (true);
}

void	AsioServer::interpretPacket(const Packet::DataPacket &packet,
					ClientObject &obj) noexcept
{
	if (packet.cmd < Packet::UNKNOWN) {
		(this->*fptr[packet.cmd])(packet, obj);
	}
}

void AsioServer::connect(const Packet::DataPacket &packet, ClientObject
&obj) noexcept
{
	std::cout << "CONNECT" << std::endl;
}

void AsioServer::disconnect(const Packet::DataPacket &packet, ClientObject
&obj) noexcept
{
	std::cout << "DISCONNECT" << std::endl;
}

void AsioServer::connected(const Packet::DataPacket &packet, ClientObject
&obj) noexcept
{
	std::cout << "CONNECTED" << std::endl;
}

void AsioServer::disconnected(const Packet::DataPacket &packet, ClientObject
&obj) noexcept
{
	std::cout << "DISCONNECTED" << std::endl;
}

void AsioServer::startGame(const Packet::DataPacket &packet, ClientObject
&obj) noexcept
{
}

void AsioServer::ready(const Packet::DataPacket &packet, ClientObject &obj)
noexcept
{
	obj.toggleReady();
}

void AsioServer::position(const Packet::DataPacket &packet, ClientObject
&obj) noexcept
{
}

void AsioServer::hit(const Packet::DataPacket &packet, ClientObject &obj)
noexcept
{
}

void AsioServer::event(const Packet::DataPacket &packet, ClientObject &obj)
noexcept
{
}
void AsioServer::pong(const Packet::DataPacket &packet, ClientObject &obj)
noexcept
{
	Logger::Log(Logger::DEBUG, "Client Ponged the server");
}
