//
// Created by romain on 18/01/18.
//

#include "AAudioComponent.hpp"
#include "PacketFactory.hpp"

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
	for (unsigned int i = 0; i < other._mediators.size() - 1; ++i) {
		this->registerToMediator(other._mediators[i]);
	}

	return *this;
}

