//
// Created by Clément Péau on 19/01/2018.
//

#include <memory>
#include "Engine/PacketList.hpp"

void Engine::PacketList::pushBack(std::unique_ptr<Packet::DataPacket> &e)
{
	_mutex.lock();
	_list.push_back(e);
	_mutex.unlock();
}

std::unique_ptr<Packet::DataPacket> Engine::PacketList::popBack()
{
	std::lock_guard<std::mutex> l(_mutex);
	if (_list.empty())
		return (nullptr);
	auto t = std::move(_list.back());
	_list.pop_back();
	return (std::move(t));
}
