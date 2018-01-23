//
// Created by Clément Péau on 13/01/2018.
//

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <boost/bind.hpp>
#include <Logger.hpp>
#include <Message.hpp>
#include "AsioClient.hpp"

client::AsioClient::AsioClient(const std::string &host) : _ioService(),
							  _isConnected(false),
							  _socket(_ioService)
{
	std::cout << "Host constructor" << std::endl;
	_socket.open(boost::asio::ip::udp::v4());
}

client::AsioClient::AsioClient() : _ioService(), _socket(_ioService),
				   _isConnected(false)
{
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

bool client::AsioClient::sendMessage(const Packet::DataPacket &packet) noexcept
{
	_socket.async_send_to(boost::asio::buffer(&packet, Packet::PACKETSIZE),
			      _receiverEndpoint,
			      boost::bind(&AsioClient::handleSendPacket,
					  this,
					  packet,
					  boost::asio::placeholders::error,
					  boost::asio::placeholders::bytes_transferred));
	return (true);
}

//TODO: changer la seed et le port
bool client::AsioClient::connect(const std::string &host) noexcept
{
	boost::asio::ip::udp::resolver resolver(_ioService);
	boost::asio::ip::udp::resolver::query query(host, "4242");
	_receiverEndpoint = *resolver.resolve(query);
	readMessage();
	while (!isConnected()) {
		using namespace std::chrono_literals;
		Packet::DataPacket packet;
		packet.cmd = Packet::CONNECT;
		packet.data.connection.seed = 0;
		sendMessage(packet);
		_ioService.poll();
		std::this_thread::sleep_for(0.2s);
	}
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
	std::cout << "Sent " << message << " of "
		"size " << std::to_string(bytesTransfered) << std::endl;
}

void client::AsioClient::handleReceive(const boost::system::error_code &error,
                                       std::size_t bytesTransfered)
{
	Message message(std::string(_data_array.begin(), _data_array.end()));
	if (message.getPacket().cmd == Packet::CONNECTED) {
		_connected = true;
		Logger::Log(Logger::DEBUG, "Client is now connected");
	} else {
		_packetList.push_back(message.getPacket());
		Logger::Log(Logger::DEBUG, std::to_string(_packetList.size()));
	}
	readMessage();
}
void client::AsioClient::handleSendPacket(const Packet::DataPacket &packet,
                                    const boost::system::error_code &error,
                                    std::size_t bytesTransfered)
{

}

void client::AsioClient::tick() noexcept
{
	_ioService.poll();
	_ioService.reset();
}

std::vector<Packet::DataPacket> client::AsioClient::getDataPacketList()
{
	std::vector<Packet::DataPacket> v;
	return (std::exchange(_packetList, v));
}
