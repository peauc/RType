//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_PLAYERWEAPONCOMPONENT_HPP
#define RTYPE_PLAYERWEAPONCOMPONENT_HPP

#include <Components/Abstracts/AInputComponent.hpp>
#include <Components/Projectiles/ShotMovementComponent.hpp>
#include <Components/Projectiles/ShotGraphicsComponent.hpp>
#include <Components/Abstracts/AWeaponComponent.hpp>

namespace Component {
	class PlayerWeaponComponent : public AWeaponComponent
	{
	public:
		PlayerWeaponComponent(Engine::Entity *parentEntity, Engine::World *parentWorld);
		~PlayerWeaponComponent() override = default;

		void update() override;

		// handle methods
		void handleEvent(Engine::Mediator::Message messageType, AComponent *sender);
	private:
		bool _event;
		bool _firing;
		unsigned int _charging;
	};
}

#endif //RTYPE_PLAYERWEAPONCOMPONENT_HPP