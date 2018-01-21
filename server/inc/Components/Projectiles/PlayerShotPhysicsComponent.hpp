//
// Created by romain on 21/01/18.
//

#ifndef RTYPE_SHOTPHYSICSCOMPONENT_HPP
#define RTYPE_SHOTPHYSICSCOMPONENT_HPP

#include "APhysicsComponent.hpp"

namespace Component {
	class PlayerShotPhysicsComponent : public APhysicsComponent
	{
	public:
		PlayerShotPhysicsComponent(Engine::Entity *parentEntity, const Engine::Hitbox &hitbox);
		~PlayerShotPhysicsComponent() override = default;

		void update() noexcept override;
	};
}

#endif //RTYPE_SHOTPHYSICSCOMPONENT_HPP
