//
// Created by Clément Péau on 13/01/2018.
//

#ifndef RTYPE_ASIOCLIENT_HPP
#define RTYPE_ASIOCLIENT_HPP

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "DataPacket.hpp"
#include "AClient.hpp"
#include "PacketInterpreterClient.hpp"

namespace client {
class AsioClient : AClient {
public:
	virtual ~AsioClient() final;
	AsioClient();
	explicit AsioClient(const std::string &host);
	bool sendMessage(const std::string &message) noexcept final;
	bool sendMessage(const DataPacket &packet) noexcept;
	bool connect(const std::string &message) noexcept final;
	
private:
	void handleSend(boost::shared_ptr<std::string> message,
	                const boost::system::error_code& error,
	                std::size_t bytesTransfered);
	void handleSendPacket(const DataPacket &packet,
	                const boost::system::error_code& error,
	                std::size_t bytesTransfered);
	void handleReceive(const boost::system::error_code& error,
	                std::size_t bytesTransfered);
	bool readMessage() noexcept;
	
	boost::asio::io_service _ioService;
	boost::asio::ip::udp::socket _socket;
	boost::asio::ip::udp::endpoint _receiverEndpoint;
	boost::array<char, 65000> _data_array;
	PacketInterpreterClient	_interpreter;
};
}

#endif //RTYPE_ASIOCLIENT_HPP
