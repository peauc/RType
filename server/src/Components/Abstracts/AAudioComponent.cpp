//
// Created by romain on 18/01/18.
//

#include "Components/Abstracts/AAudioComponent.hpp"
#include "Factories/PacketFactory.hpp"

Component::AAudioComponent::AAudioComponent(Engine::Entity *parentEntity, Engine::Game *parentGame) :
		AComponent(parentEntity), _parentGame(parentGame)
{
}

void Component::AAudioComponent::addSoundPacket(unsigned char soundId, bool repeat) noexcept
{
	this->_parentGame->pushDataPacket(PacketFactory::createSoundPacket(soundId, false, repeat));
}

Component::AAudioComponent &Component::AAudioComponent::operator=(const Component::AAudioComponent &other) noexcept
{
	this->_parentGame = other._parentGame;
	this->_soundIds = other._soundIds;

	return *this;
}

