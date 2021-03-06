//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_PLAYERWEAPONCOMPONENT_HPP
#define RTYPE_PLAYERWEAPONCOMPONENT_HPP

#include "AInputComponent.hpp"
#include "ShotMovementComponent.hpp"
#include "ShotGraphicsComponent.hpp"
#include "AWeaponComponent.hpp"

namespace Component {
	class PlayerWeaponComponent : public AWeaponComponent
	{
	public:
		PlayerWeaponComponent(Engine::Entity *parentEntity, Engine::Game *parentGame);
		~PlayerWeaponComponent() override = default;

		void update() noexcept override;

		// handle methods
		void handleEvent(Engine::Mediator::Message messageType, AComponent *sender) noexcept;

		AComponent *clone(Engine::Entity *parentEntity) const noexcept override;
	private:
		bool _event;
		bool _firing;
		unsigned int _charge;
		bool _isCharging;
	};
}

#endif //RTYPE_PLAYERWEAPONCOMPONENT_HPP
