//
// Created by romain on 17/01/18.
//

#ifndef RTYPE_OBSERVER_HPP
#define RTYPE_OBSERVER_HPP

#include "AComponent.hpp"

namespace Engine {
	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual void receive(Mediator::Message messageType, AComponent *sender) = 0;
	};
}

#endif //RTYPE_OBSERVER_HPP
