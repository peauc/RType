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
		enum Message
		{
			NEW_EVENT,
			GRAPHICS_REGISTERING,
			DEATH,
			HIT,
			CHECK_COLLISION,
			GET_IMPACT_DAMAGES,
			CANCEL_MOVE,
			CAMERA_REPOSITION,
			MOVE,
			TRIGGER_ZONE
		};

		Mediator() = default;
		~Mediator() = default;

		void send(Message message, AComponent *sender)  noexcept;
		void registerComponent(AComponent *component)  noexcept;
		void unregisterComponent(AComponent *component)  noexcept;

	private:
		std::vector<AComponent *> _subjects;
	};
}

#endif //RTYPE_MEDIATOR_HPP
