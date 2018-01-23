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

void AsioServer::handleSend(const Message &,
                            const boost::system::error_code &error,
                            std::size_t)
{
	
	if (error) {
		Logger::Log(Logger::MAJOR, error.message());
	}
}

void AsioServer::startReceive()
{
	_socket.async_receive_from(boost::asio::buffer(_array), _dummy_endpoint,
		boost::bind(&AsioServer::handleReceive, this,
		            boost::asio::placeholders::error,
		            boost::asio::placeholders::bytes_transferred));
}

void AsioServer::handleReceive(const boost::system::error_code &,
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
		
		if (message.getPacket().cmd == Packet::CONNECT) {
			Logger::Log(Logger::DEBUG, std::string("New client, "
								       "command"));
			_lobbyList.addClientToLobby(tmp
				, message.getPacket()
			                                        .data
			                                        .connection
			                                        .seed);
			sendMessage(tmp, Packet::DataPacket(Packet::CONNECTED));
		}
	}
	//_lobbyList.dump();
}

bool AsioServer::tick()
{
	_ioService.poll();
	_ioService.reset();
	_lobbyList.checkTimeout();
	auto t = _lobbyList.getPacketFromGames();
	if (t != nullptr) {
		for(auto it = t->begin(); it < t->end(); it++) {
			for(auto it2 = it->first->begin();
			    it2 < it->first->end(); it2++) {
				for(auto clients = it->second->getClientList().begin();
				    clients <
				    it->second->getClientList().end(); clients++) {
					sendMessage(*clients, *(it2->get()));
				}
			}
		}
	}
	return (true);
}

void	AsioServer::interpretPacket(const Packet::DataPacket &packet,
					ClientObject &obj) noexcept
{
	if (packet.cmd < Packet::UNKNOWN) {
		(this->*fptr[packet.cmd])(packet, obj);
	}
}

void AsioServer::connect(const Packet::DataPacket &, ClientObject
&) noexcept
{
	std::cout << "CONNECT" << std::endl;
}

void AsioServer::disconnect(const Packet::DataPacket &, ClientObject
&) noexcept
{
	std::cout << "DISCONNECT" << std::endl;
}

void AsioServer::connected(const Packet::DataPacket &, ClientObject
&) noexcept
{
	std::cout << "CONNECTED" << std::endl;
}

void AsioServer::disconnected(const Packet::DataPacket &, ClientObject
&) noexcept
{
	std::cout << "DISCONNECTED" << std::endl;
}

void AsioServer::startGame(const Packet::DataPacket &, ClientObject
&) noexcept
{
	std::cout << "LOGGER" << std::endl;
}

void AsioServer::ready(const Packet::DataPacket &, ClientObject &obj)
noexcept
{
	if (!_lobbyList.getClientLobby(obj)->isStarted() && !obj.isReady())
		obj.toggleReady();
	sendMessage(obj, Packet::DataPacket(Packet::READY));
	if (_lobbyList.getClientLobby(obj)->isReady() && !_lobbyList
								 .getClientLobby(obj)->isStarted()) {
		Logger::Log(Logger::DEBUG, "Starting game :)");
		_lobbyList.getClientLobby(obj)->startGame();
		for (auto &t: _lobbyList.getClientLobby(obj)->getClientList()) {
			sendMessage(t, Packet::DataPacket(Packet::STARTGAME));
		}
	}
	else {
		Logger::Log(Logger::DEBUG, "Game is not ready to start");
	}
}

void AsioServer::position(const Packet::DataPacket &, ClientObject
&) noexcept
{
}

void AsioServer::event(const Packet::DataPacket &packet, ClientObject &obj)
noexcept
{
	Packet::Input input = packet.data.input;
	
	std::unique_ptr<Engine::Event> e = std::make_unique<Engine::Event>
		(obj.getEntityID());
	
	e->_chargingShot = input.charged;
	e->_shotReleased = input.shot;
	e->_xVelocity = input.xVelocity;
	e->_yVelocity = input.yVelocity;
	std::cout << "Event Method : "<< e->_yVelocity << " " << e->_xVelocity
		  << std::endl << e->_entityId << std::endl;
	_lobbyList.getClientLobby(obj)->pushEventInList(e);
}
void AsioServer::pong(const Packet::DataPacket &, ClientObject &)
noexcept
{
	Logger::Log(Logger::DEBUG, "Client Ponged the server");
}
