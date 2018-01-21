//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP
#define RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/Event.hpp>
#include <queue>
#include <utility>
#include <Engine/EventList.hpp>
#include "Components/Abstracts/AInputComponent.hpp"

namespace Component {
	class PlayerInputComponent : public AInputComponent
	{
	public:
		explicit PlayerInputComponent(Engine::Entity *parentEntity,
									  Engine::EventList &eventList);
		~PlayerInputComponent() override = default;

		void update() override;
	private:
		Engine::EventList &_eventList;
	};
}

#endif //RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP
