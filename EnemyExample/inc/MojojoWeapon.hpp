//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_MojojoWeapon_HPP
#define RTYPE_MojojoWeapon_HPP

#include "AWeaponComponent.hpp"

namespace Component {
	class MojojoWeapon : public AWeaponComponent
	{
	public:
		MojojoWeapon(Engine::Entity *parentEntity, Engine::Game *parentGame);
		~MojojoWeapon() override = default;

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

#endif //RTYPE_MojojoWeapon_HPP
