//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_ENEMYMOVECOMPONENT_HPP
#	define RTYPE_ENEMYMOVECOMPONENT_HPP

#	include "Event.hpp"
#	include "AMovementComponent.hpp"

namespace Component {
	class EnemyMoveComponent : public AMovementComponent
	{
	public:
		explicit EnemyMoveComponent(Engine::Entity *parentEntity, unsigned int lifetime);
		~EnemyMoveComponent() override = default;

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
		unsigned int _lifetime;
	};
}

#endif //RTYPE_ENEMYMOVECOMPONENT_HPP
