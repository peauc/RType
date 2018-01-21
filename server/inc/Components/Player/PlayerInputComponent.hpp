//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP
#define RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP

#include <queue>
#include <utility>
#include "EventList.hpp"
#include "AInputComponent.hpp"
#include "AComponent.hpp"
#include "Event.hpp"

namespace Component {
	class PlayerInputComponent : public AInputComponent
	{
	public:
		explicit PlayerInputComponent(Engine::Entity *parentEntity,
									  Engine::EventList *eventList);
		~PlayerInputComponent() override = default;

		void update() noexcept override;

		AComponent *clone(Engine::Entity *parentEntity) const noexcept override;

	private:
		Engine::EventList *_eventList;
	};
}

#endif //RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP
