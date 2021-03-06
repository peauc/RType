//
// Created by romain on 12/01/18.
//

#ifndef RTYPE_DEFAULTPLAYERMOVEMENTCOMPONENT_HPP
#define RTYPE_DEFAULTPLAYERMOVEMENTCOMPONENT_HPP

#include "Event.hpp"
#include "AMovementComponent.hpp"

namespace Component {
	class PlayerMovementComponent : public AMovementComponent
	{
	public:
		explicit PlayerMovementComponent(Engine::Entity *parentEntity);
		~PlayerMovementComponent() override = default;

		void update() noexcept override;

		// handle methods
		void handleEvent(Engine::Mediator::Message messageType, AComponent *sender) noexcept;
		void handleCameraReposition(Engine::Mediator::Message messageType, AComponent *sender) noexcept;

		AComponent *clone(Engine::Entity *parentEntity) const noexcept override;
	private:
		double _baseSpeed;
		double _lateralBaseSpeed;
		double _inputSpeed;
		double _lateralInputSpeed;
		double _xInput;
		double _yInput;
	};
}

#endif //RTYPE_DEFAULTPLAYERMOVEMENTCOMPONENT_HPP
