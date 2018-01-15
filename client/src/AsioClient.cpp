//
// Created by Clément Péau on 13/01/2018.
//

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include <boost/bind.hpp>
#include <Logger.hpp>
#include <Message.hpp>
#include "AsioClient.hpp"

client::AsioClient::AsioClient(const std::string &host) : _ioService(),
                                                          _socket(_ioService)
{
	std::cout << "Host constructor" << std::endl;
	_socket.open(boost::asio::ip::udp::v4());
}


client::AsioClient::AsioClient() : _ioService(), _socket(_ioService)
{
	std::cout << "Regular constructor" << std::endl;
	_socket.open(boost::asio::ip::udp::v4());
}

client::AsioClient::~AsioClient()
{
	_socket.close();
}

bool client::AsioClient::sendMessage(const std::string &message) noexcept
{
	std::cout << "Preparing to send" << '\n';
	boost::shared_ptr<std::string> ptr(new std::string(message));
	
	_socket.async_send_to(boost::asio::buffer(*ptr),
	                      _receiverEndpoint,
	                      boost::bind(&AsioClient::handleSend,
	                                  this, ptr,
	                                  boost::asio::placeholders::error,
	                                  boost::asio::placeholders::bytes_transferred));
	return (true);
}

bool client::AsioClient::sendMessage(const DataPacket &packet) noexcept
{
	//Logger::Log(Logger::DEBUG, "Preparing to send");
	_socket.async_send_to(boost::asio::buffer(&packet,
	                                          PACKETSIZE)
	, _receiverEndpoint, boost::bind(&AsioClient::handleSendPacket, this,
	                                 packet,
	                                 boost::asio::placeholders::error,
	                                 boost::asio::placeholders::bytes_transferred));
	return (true);
}

bool client::AsioClient::connect(const std::string &host) noexcept
{
	boost::asio::ip::udp::resolver resolver(_ioService);
	boost::asio::ip::udp::resolver::query query(host, "4242");
	_receiverEndpoint = *resolver.resolve(query);
	return (true);
}

bool client::AsioClient::readMessage() noexcept
{
	_socket.async_receive_from(boost::asio::buffer(_data_array),
	                           _receiverEndpoint, boost::bind(&AsioClient::handleReceive,
		                            this,
		                            boost::asio::placeholders::error,
		                            boost::asio::placeholders::bytes_transferred));
	return (true);
}

void client::AsioClient::handleSend(boost::shared_ptr<std::string> message,
                                    const boost::system::error_code &error,
                                    std::size_t bytesTransfered)
{
	std::cout << "Received " << message << " of "
		"size " << std::to_string(bytesTransfered) << std::endl;
	
}

void client::AsioClient::handleReceive(const boost::system::error_code &error,
                                       std::size_t bytesTransfered)
{
	std::cout << "Sent " << std::to_string(bytesTransfered) << std::endl;
}
void client::AsioClient::handleSendPacket(const DataPacket &packet,
                                    const boost::system::error_code &error,
                                    std::size_t bytesTransfered)
{
	std::cout << "Received a packet of "
		"size " << std::to_string(bytesTransfered) << std::endl;
}
