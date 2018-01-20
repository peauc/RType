//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_ENEMYMOVECOMPONENT_HPP
#	define RTYPE_ENEMYMOVECOMPONENT_HPP

#	include <Engine/Event.hpp>
#	include "Components/Abstracts/AMovementComponent.hpp"

namespace Component {
	class EnemyMovementComponent : public AMovementComponent
	{
	public:
		explicit EnemyMovementComponent(Engine::Entity *parentEntity);
		~EnemyMovementComponent() override = default;

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
