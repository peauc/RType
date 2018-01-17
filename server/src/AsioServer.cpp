//
// Created by Clément Péau on 10/01/2018.
//

#include <boost/functional.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <iostream>
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
	//Logger::Log(Logger::DEBUG, "Received " + message.getRawMessage()
	 //                          + " " + std::to_string(nbWritten));
	ClientObject tmp(_dummy_endpoint);
	Lobby *t;
	
	if (_lobbyList.isClientContained(tmp)) {
		t = _lobbyList.getClientLobby(tmp);
		_interpreter.interpretPacket(message.getPacket());
	}
	else {
		std::cout << "Created a new client" << '\n';
		if (message.getPacket().cmd == Packet::CONNECT) {
			_lobbyList.addClientToLobby(tmp);
		}
	}
	_lobbyList.dump();
	
}

bool AsioServer::tick()
{
	_ioService.run();
	_ioService.reset();
	return (true);
}
