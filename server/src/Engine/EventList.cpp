//
// Created by Clément Péau on 17/01/2018.
//

#include <algorithm>
#include "EventList.hpp"

void Engine::EventList::pushBack(std::unique_ptr<Engine::Event> &e)
{
	_mutex.lock();
	_list.push_back(std::move(e));
	_mutex.unlock();
}

std::vector<std::unique_ptr<Engine::Event>> &Engine::EventList::getEvents()
{
	return _list;
}

const std::vector<std::unique_ptr<Engine::Event>> &Engine::EventList::getEvents() const
{
	return _list;
}

std::unique_ptr<Engine::Event> Engine::EventList::getEventById(size_t id)
noexcept
{
	std::lock_guard<std::mutex> l(_mutex);
	auto t = std::find_if(_list.begin(), _list.end(), [id]
		(std::unique_ptr<Engine::Event> &e){
		return (e->_entityId == id);
	});
	if (t == _list.end())
		return (nullptr);
	_list.erase(t);
	return (std::move(*t));
}
