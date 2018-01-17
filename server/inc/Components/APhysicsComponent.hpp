//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_APHYSICSCOMPONENT_HPP
#define RTYPE_APHYSICSCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/Hitbox.hpp>

namespace Component {
	class APhysicsComponent : public Engine::AComponent
	{
	public:
		explicit APhysicsComponent(Engine::Entity *entity);
		~APhysicsComponent() override = default;

		virtual void triggerCollision(APhysicsComponent &other) = 0;
	private:

	};
}

#endif //RTYPE_APHYSICSCOMPONENT_HPP
