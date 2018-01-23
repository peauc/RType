//
// Created by romain on 19/01/18.
//

#include "AWeaponComponent.hpp"

Component::AWeaponComponent::AWeaponComponent(Engine::Entity *parentEntity, Engine::Game *parentGame, unsigned int cooldown) :
		AComponent(parentEntity), _parentGame(parentGame), _cooldown(cooldown), _frameSinceShot(cooldown)
{
}

Component::AWeaponComponent &Component::AWeaponComponent::operator=(const Component::AWeaponComponent &other) noexcept
{
	this->_parentGame = other._parentGame;
	this->_cooldown = other._cooldown;
	this->_frameSinceShot = other._cooldown;
	this->_shotAngle = other._shotAngle;
	this->_shotRelativeOrigin = other._shotRelativeOrigin;

	return *this;
}
