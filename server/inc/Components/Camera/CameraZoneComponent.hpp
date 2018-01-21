//
// Created by romain on 19/01/18.
//

#ifndef RTYPE_CAMERAZONECOMPONENT_HPP
#define RTYPE_CAMERAZONECOMPONENT_HPP

#include "Components/Abstracts/APhysicsComponent.hpp"

namespace Component {
	class CameraZoneComponent : public APhysicsComponent
	{
	public:
		CameraZoneComponent(Engine::Entity *parentEntity, Engine::Hitbox hitbox);
		~CameraZoneComponent() override = default;

		void update() noexcept override;

		// handle methods
		void handleCheckCollision(Engine::Mediator::Message, AComponent *sender) noexcept override;
	};
}

#endif //RTYPE_CAMERAZONECOMPONENT_HPP
