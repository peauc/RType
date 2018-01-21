//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_ENEMYMOVECOMPONENT_HPP
#	define RTYPE_ENEMYMOVECOMPONENT_HPP

#	include "Engine/AComponent.hpp"
#	include "Event.hpp"
#	include "Abstracts/AMovementComponent.hpp"
#	include "Engine/Commands/TransformPositionCommand.hpp"
#	include "Components/Abstracts/AInputComponent.hpp"

namespace Component {
	class EnemyMoveComponent : public AMovementComponent
	{
	public:
		explicit EnemyMoveComponent(Engine::Entity *parentEntity);
		~EnemyMoveComponent() override = default;

		void update() override;

		// handle methods
		void handleEvent(Engine::Mediator::Message messageType, AComponent *sender);
	private:
		float _baseSpeed;
		float _lateralBaseSpeed;
		float _maxSpeed;
		float _lateralMaxSpeed;
		float _xInput;
		float _yInput;
	};
}

#endif //RTYPE_ENEMYMOVECOMPONENT_HPP
