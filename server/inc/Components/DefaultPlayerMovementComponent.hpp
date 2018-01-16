//
// Created by romain on 12/01/18.
//

#ifndef RTYPE_DEFAULTPLAYERMOVEMENTCOMPONENT_HPP
#define RTYPE_DEFAULTPLAYERMOVEMENTCOMPONENT_HPP

#include <Engine/Event.hpp>
#include "AMovementComponent.hpp"

namespace Component {
	class DefaultPlayerMovementComponent : public AMovementComponent
	{
	public:
		explicit DefaultPlayerMovementComponent(Engine::Entity *parentEntity);
		~DefaultPlayerMovementComponent() override = default;

		void update() override;

		// handle methods
		void handleEvent(Engine::Message messageType, AComponent *sender);
	private:
		float _baseSpeed;
		float _lateralBaseSpeed;
		float _maxSpeed;
		float _lateralMaxSpeed;
		float _xInput;
		float _yInput;
	};
}

#endif //RTYPE_DEFAULTPLAYERMOVEMENTCOMPONENT_HPP
