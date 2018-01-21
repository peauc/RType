//
// Created by romain on 12/01/18.
//

#ifndef RTYPE_DEFAULTPLAYERMOVEMENTCOMPONENT_HPP
#define RTYPE_DEFAULTPLAYERMOVEMENTCOMPONENT_HPP

#include <Engine/Event.hpp>
#include "Components/Abstracts/AMovementComponent.hpp"

namespace Component {
	class PlayerMovementComponent : public AMovementComponent
	{
	public:
		explicit PlayerMovementComponent(Engine::Entity *parentEntity);
		~PlayerMovementComponent() override = default;

		void update() override;

		// handle methods
		void handleEvent(Engine::Mediator::Message messageType, AComponent *sender);
		void handleCameraReposition(Engine::Mediator::Message messageType, AComponent *sender);
	private:
		double _baseSpeed;
		double _lateralBaseSpeed;
		double _maxSpeed;
		double _lateralMaxSpeed;
		double _xInput;
		double _yInput;
	};
}

#endif //RTYPE_DEFAULTPLAYERMOVEMENTCOMPONENT_HPP
