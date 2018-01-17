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
#include "PacketInterpreterServer.hpp"
#include "LobbyContainer.hpp"

class AsioServer : public IServer {
public:
	bool
	sendMessage(const ClientObject &client, const IMessage &message) final;
	AsioServer();
	~AsioServer() final;
	virtual bool tick();
	virtual bool stop() final;
	virtual bool start() final;

private:
	void startReceive();
	void handleSend(boost::shared_ptr<std::string> message,
	                const boost::system::error_code& error,
	                std::size_t bytesTransfered);
	void handleReceive(const boost::system::error_code& error,
	                    std::size_t nbWritten);
	
	LobbyContainer _lobbyList;
	std::vector<boost::asio::ip::udp::endpoint> _endpointList;
	boost::asio::ip::udp::endpoint _endpoint;
	boost::asio::ip::udp::endpoint _dummy_endpoint;
	boost::asio::io_service _ioService;
	boost::asio::ip::udp::socket _socket;
	boost::array<char, 65000> _array;
	PacketInterpreterServer	_interpreter;
};

#endif //ASIOSERVER_HPP
