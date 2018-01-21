//
// Created by romain on 19/01/18.
//

#include <Components/Abstracts/AWeaponComponent.hpp>

Component::AWeaponComponent::AWeaponComponent(Engine::Entity *parentEntity, Engine::Game *parentGame) :
		AComponent(parentEntity), _parentGame(parentGame)
{
}
