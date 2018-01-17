//
// Created by romain on 17/01/18.
//

#ifndef RTYPE_PLAYERPHYSICSCOMPONENT_HPP
#define RTYPE_PLAYERPHYSICSCOMPONENT_HPP

#include "APhysicsComponent.hpp"

namespace Component {
	class PlayerPhysicsComponent : public APhysicsComponent
	{
	public:
		explicit PlayerPhysicsComponent(Engine::Entity *entity);
		~PlayerPhysicsComponent() override = default;

		void triggerCollision(APhysicsComponent &other) override;
		void update() override;
	};
}

#endif //RTYPE_PLAYERPHYSICSCOMPONENT_HPP
