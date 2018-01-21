//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_AWEAPONCOMPONENT_HPP
#define RTYPE_AWEAPONCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/World.hpp>

namespace Component {
	class AWeaponComponent : public Engine::AComponent
	{
	public:
		AWeaponComponent(Engine::Entity *parentEntity, Engine::Game *parentGame);
		~AWeaponComponent() override = default;

		AWeaponComponent &operator=(const AWeaponComponent &other);
	protected:
		Engine::Game *_parentGame;
		double _shotAngle;
		Vector2d _shotRelativeOrigin;
		unsigned int _cooldown;
	};
}

#endif //RTYPE_AWEAPONCOMPONENT_HPP
