//
// Created by Clément Péau on 17/01/2018.
//

#ifndef RTYPE_EVENTLIST_HPP
#define RTYPE_EVENTLIST_HPP

#include <vector>
#include <mutex>
#include "Event.hpp"

namespace Engine {
class EventList {
public:
	EventList();
	~EventList();
	std::vector<std::unique_ptr<Engine::Event>> &getEvents();
	const std::vector<std::unique_ptr<Engine::Event>> &getEvents() const;
	void pushBack(std::unique_ptr<Engine::Event> &e);
	Engine::Event popBack();
private:
	std::vector<std::unique_ptr<Engine::Event>> _events;
	std::mutex _mutex;
};
}
#endif //RTYPE_EVENTLIST_HPP
