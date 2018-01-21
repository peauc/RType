//
// Created by romain on 21/01/18.
//

#ifndef RTYPE_ENEMYSHOTPHYSICSCOMPONENT_HPP
#define RTYPE_ENEMYSHOTPHYSICSCOMPONENT_HPP

#include "Components/Abstracts/APhysicsComponent.hpp"

namespace Component {
	class EnemyShotPhysicsComponent : public APhysicsComponent
	{
	public:
		EnemyShotPhysicsComponent(Engine::Entity *parentEntity, const Engine::Hitbox &hitbox);
		~EnemyShotPhysicsComponent() override = default;

		void update() noexcept override;
	};
}

#endif //RTYPE_ENEMYSHOTPHYSICSCOMPONENT_HPP
