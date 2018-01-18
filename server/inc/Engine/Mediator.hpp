//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_MEDIATOR_HPP
#define RTYPE_MEDIATOR_HPP

#include <vector>
#include <algorithm>
#include "AComponent.hpp"

namespace Engine {
	class AComponent;
	class Mediator
	{
	public:
		enum Message {
			NEW_EVENT,
			GRAPHICS_REGISTERING,
			DEATH,
			HIT,
		};

		Mediator() = default;
		~Mediator() = default;

		void send(Message message, AComponent *sender);
		void registerComponent(AComponent *component);
		void unregisterComponent(AComponent *component);

	private:
		std::vector<AComponent *> _subjects;
	};
}

#endif //RTYPE_MEDIATOR_HPP
