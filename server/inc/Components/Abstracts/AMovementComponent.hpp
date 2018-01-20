//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_AMOVEMENTCOMPONENT_HPP
#define RTYPE_AMOVEMENTCOMPONENT_HPP

#include <Engine/Entity.hpp>
#include <Engine/AComponent.hpp>
#include <Engine/Event.hpp>

namespace Component {
	class AMovementComponent : public Engine::AComponent
	{
	public:
		explicit AMovementComponent(Engine::Entity *parentEntity);
		~AMovementComponent() override = default;

		// handle methods
		void handleCancelMove(Engine::Mediator::Message messageType, Engine::AComponent *sender);
	protected:
		std::unique_ptr<Engine::Event> _event;
		Vector2d _lastMove;
	};
}

#endif //RTYPE_AMOVEMENTCOMPONENT_HPP
