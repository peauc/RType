//
// Created by Clément Péau on 17/01/2018.
//

#include "Engine/EventList.hpp"

Engine::EventList::~EventList()
{
}

Engine::EventList::EventList()
{
}

void Engine::EventList::pushBack(std::unique_ptr<Engine::Event> &e)
{
	_mutex.lock();
	_events.push_back(std::move(e));
	_mutex.unlock();
}

Engine::Event Engine::EventList::popBack()
{
	_mutex.lock();
	std::unique_ptr<Engine::Event> &e = _events.back();
	_mutex.unlock();
	return (*e.get());
}
std::vector<std::unique_ptr<Engine::Event>> &Engine::EventList::getEvents()
{
	return _events;
}
const std::vector<std::unique_ptr<Engine::Event>> &Engine::EventList::getEvents() const
{
	return _events;
}

