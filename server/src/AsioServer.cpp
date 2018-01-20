//
// Created by Clément Péau on 10/01/2018.
//

#include <boost/functional.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>
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

bool AsioServer::sendMessage(const ClientObject &client, const Packet::DataPacket
&message)
{
	_socket.async_send_to(boost::asio::buffer(&message, Packet::PACKETSIZE),
	                      client.getEndpoint(),
	                      boost::bind(&AsioServer::handleSend,
	                                  this, message,
	                                  boost::asio::placeholders::error,
	                                  boost::asio::placeholders::bytes_transferred));
	return (true);
}

void AsioServer::handleSend(const Message &message,
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
	_array.assign(0);
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
		Logger::Log(Logger::DEBUG, std::string("New client, command "
							       "| " +
							       std::to_string(message
			.getPacket().cmd) + "|"));
		
		if (message.getPacket().cmd == Packet::CONNECT) {
			_lobbyList.addClientToLobby(tmp
				, message.getPacket()
			                                        .data
			                                        .connection
			                                        .seed);
			sendMessage(tmp, Packet::DataPacket(Packet::CONNECTED));
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
	Logger::Log(Logger::DEBUG, "Command n" + packet.cmd);
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
	if (_lobbyList.getClientLobby(obj)->isReady()) {
		Logger::Log(Logger::DEBUG, "Starting game :)");
		_lobbyList.getClientLobby(obj)->startGame();
		for (auto &t: _lobbyList.getClientLobby(obj)->getClientList
			()) {
			sendMessage(t, Packet::DataPacket(Packet::STARTGAME));
		}
	}
	else {
		Logger::Log(Logger::DEBUG, "Game is not ready to start");
	}
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
