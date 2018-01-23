//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_MOJOJOMOVE_HPP
#	define RTYPE_MOJOJOMOVE_HPP

#	include "Event.hpp"
#	include "AMovementComponent.hpp"

namespace Component {
	class MojojoMove : public AMovementComponent
	{
	public:
		explicit MojojoMove(Engine::Entity *parentEntity);
		~MojojoMove() override = default;

		void update() noexcept;

		// handle methods
		void handleEvent(Engine::Mediator::Message messageType, AComponent *sender);
		AComponent *clone(Engine::Entity *parentEntity) const noexcept;

	private:
		float _baseSpeed;
		float _lateralBaseSpeed;
		float _maxSpeed;
		float _lateralMaxSpeed;
		float _xInput;
		float _yInput;
	};
}

#endif //RTYPE_MOJOJOMOVE_HPP
