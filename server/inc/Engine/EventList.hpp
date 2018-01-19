//
// Created by Clément Péau on 17/01/2018.
//

#ifndef RTYPE_EVENTLIST_HPP
#define RTYPE_EVENTLIST_HPP

#include <vector>
#include <mutex>
#include <memory>
#include "Event.hpp"

namespace Engine {
class EventList {
public:
	EventList() = default;
	~EventList() = default;
	
	std::unique_ptr<Engine::Event> getEventById(size_t id) noexcept;
	std::vector<std::unique_ptr<Engine::Event>> &getEvents();
	const std::vector<std::unique_ptr<Engine::Event>> &getEvents() const;
	void pushBack(std::unique_ptr<Engine::Event> &e);
private:
	std::vector<std::unique_ptr<Engine::Event>> _list;
	std::mutex _mutex;
};
}
#endif //RTYPE_EVENTLIST_HPP
