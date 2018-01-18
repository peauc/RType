//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP
#define RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/Event.hpp>
#include <queue>
#include <utility>
#include "Components/Abstracts/AInputComponent.hpp"

namespace Component {
	class PlayerInputComponent : public AInputComponent
	{
	public:
		explicit PlayerInputComponent(Engine::Entity *parentEntity,
											 std::vector<std::unique_ptr<Engine::Event>> &gameEvents);
		~PlayerInputComponent() = default;

		void update();
	private:
		std::vector<std::unique_ptr<Engine::Event>> &_gameEvents;
	};
}

#endif //RTYPE_DEFAULTPLAYERINPUTCOMPONENT_HPP
