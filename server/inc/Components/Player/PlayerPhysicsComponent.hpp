//
// Created by romain on 19/01/18.
//

#ifndef RTYPE_PLAYERPHYSICSCOMPONENT_HPP
#define RTYPE_PLAYERPHYSICSCOMPONENT_HPP

#include <Components/Abstracts/APhysicsComponent.hpp>

namespace Component {
	class PlayerPhysicsComponent : public APhysicsComponent
	{
	public:
		PlayerPhysicsComponent(Engine::Entity *parentEntity, Engine::Hitbox *hitbox);
		~PlayerPhysicsComponent() override = default;

		void update() override;
		void triggerCollision(APhysicsComponent &other);
	};
}

#endif //RTYPE_PLAYERPHYSICSCOMPONENT_HPP
