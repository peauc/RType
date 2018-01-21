/*
** EPITECH  PROJECT , 2020
** r-type
** File  description:
** 	No description
*/
#ifndef ASIOSERVER_HPP
#define ASIOSERVER_HPP

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "IServer.hpp"
#include "Message.hpp"
#include "PacketInterpreterServer.hpp"
#include "LobbyContainer.hpp"

class AsioServer : public IServer {
public:
	bool
	sendMessage(const ClientObject &client, const Packet::DataPacket &message)
	final;
	AsioServer();
	~AsioServer() final;
	virtual bool tick();
	virtual bool stop() final;
	virtual bool start() final;

private:
	void	interpretPacket(const Packet::DataPacket &packet,
				    ClientObject &obj) noexcept;
	void	connect(const Packet::DataPacket &packet, ClientObject &obj) noexcept;
	void	disconnect(const Packet::DataPacket &packet, ClientObject &obj) noexcept;
	void	connected(const Packet::DataPacket &packet, ClientObject &obj) noexcept;
	void	disconnected(const Packet::DataPacket &packet, ClientObject &obj) noexcept;
	void	startGame(const Packet::DataPacket &packet, ClientObject &obj) noexcept;
	void	ready(const Packet::DataPacket &packet, ClientObject &obj) noexcept;
	void	position(const Packet::DataPacket &packet, ClientObject &obj) noexcept;
	void	hit(const Packet::DataPacket &packet, ClientObject &obj) noexcept;
	void	event(const Packet::DataPacket &packet, ClientObject &obj) noexcept;
	void	pong(const Packet::DataPacket &packet, ClientObject &obj) noexcept;
	
	void startReceive();
	void handleSend(const Message &message,
	                const boost::system::error_code& error,
	                std::size_t bytesTransfered);
	void handleReceive(const boost::system::error_code& error,
	                    std::size_t nbWritten);
	
	void (AsioServer::*fptr[Packet::UNKNOWN])(const Packet::DataPacket
						  &packet, ClientObject &obj);
	LobbyContainer _lobbyList;
	std::vector<boost::asio::ip::udp::endpoint> _endpointList;
	boost::asio::ip::udp::endpoint _endpoint;
	boost::asio::ip::udp::endpoint _dummy_endpoint;
	boost::asio::io_service _ioService;
	boost::asio::ip::udp::socket _socket;
	boost::array<char, 65000> _array;
};

#endif //ASIOSERVER_HPP
