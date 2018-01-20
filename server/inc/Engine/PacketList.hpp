//
// Created by Clément Péau on 19/01/2018.
//

#ifndef RTYPE_PACKETLIST_HPP
#define RTYPE_PACKETLIST_HPP
#include <DataPacket.hpp>
#include <memory>
#include <mutex>
#include <vector>

namespace Engine {
class PacketList {
public:
	PacketList() = default;
	~PacketList() = default;
	
	void pushBack(std::unique_ptr<Packet::DataPacket> &e);
	std::unique_ptr<Packet::DataPacket> popBack();
private:
	std::vector<std::unique_ptr<Packet::DataPacket>> _list;
	std::mutex _mutex;
};
}

#endif //RTYPE_PACKETLIST_HPP
