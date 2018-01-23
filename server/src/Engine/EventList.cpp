//
// Created by Clément Péau on 17/01/2018.
//

#include <algorithm>
#include <iostream>
#include "EventList.hpp"
#include "Logger.hpp"

void Engine::EventList::pushBack(std::unique_ptr<Engine::Event> e)
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
{
	std::lock_guard<std::mutex> l(_mutex);
	auto t = std::find_if(_list.begin(), _list.end(),
			      [id](std::unique_ptr<Engine::Event> &e) {
				      if (!e.get())
					      return (false);
				      return (e->_entityId == id);
	});
	if (t == _list.end())
		return (nullptr);
	auto e = std::move(*t);
	_list.erase(t);

	auto d = std::find_if(_list.begin(), _list.end(),
	[](std::unique_ptr<Engine::Event> &e) {
		return (e.get() == nullptr);
	});
	if (d != _list.end())
		_list.erase(d);


//	if (e.get()) {
//		std::cout << "Recup method" << e->_xVelocity << " " <<
//								     e->_yVelocity
//			  << std::endl;
//	}
	return (std::move(e));
}
