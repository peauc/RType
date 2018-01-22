//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_AWEAPONCOMPONENT_HPP
#define RTYPE_AWEAPONCOMPONENT_HPP

#include "AComponent.hpp"
#include "World.hpp"

namespace Component {
	class AWeaponComponent : public Engine::AComponent
	{
	public:
		AWeaponComponent(Engine::Entity *parentEntity, Engine::Game *parentGame, unsigned int cooldown);
		~AWeaponComponent() override = default;

		// operator overloads
		AWeaponComponent &operator=(const AWeaponComponent &other) noexcept ;
	protected:
		Engine::Game *_parentGame;
		double _shotAngle;
		Vector2d _shotRelativeOrigin;
		unsigned int _cooldown;
		unsigned int _frameSinceShot;
	};
}

#endif //RTYPE_AWEAPONCOMPONENT_HPP
