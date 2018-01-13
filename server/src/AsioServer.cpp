//
// Created by Clément Péau on 10/01/2018.
//

#include <boost/functional.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <Logger.hpp>
#include <iostream>
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

bool AsioServer::sendMessage(const IClient &client, const IMessage &message)
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
                               std::size_t nbWritten)
{
	Logger::Log(Logger::DEBUG, "Received " + std::to_string(nbWritten));
	boost::shared_ptr<std::string> toot(new std::string("toto"));
	
	if (std::find(_endpointList.begin(), _endpointList.end(),
	              _dummy_endpoint) == _endpointList.end())
	{
		std::cout << "New connection" << std::endl;
		_endpointList.emplace_back(boost::asio::ip::udp::endpoint
			                        (_dummy_endpoint));
	}
	_socket.async_send_to(boost::asio::buffer(*toot),
	                      _dummy_endpoint,
	                      boost::bind(&AsioServer::handleSend,
	                                  this, toot,
	                                  boost::asio::placeholders::error,
	                                  boost::asio::placeholders::bytes_transferred));
	startReceive();
}
bool AsioServer::tick()
{
	_ioService.run();
	_ioService.reset();
	return (true);
}
