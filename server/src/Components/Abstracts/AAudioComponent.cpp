//
// Created by romain on 18/01/18.
//

#include <Components/Abstracts/AAudioComponent.hpp>
#include <Factories/PacketFactory.hpp>

Component::AAudioComponent::AAudioComponent(Engine::Entity *parentEntity, Engine::Game *parentGame) :
		AComponent(parentEntity), _parentGame(parentGame)
{
}

void Component::AAudioComponent::addSoundPacket(unsigned char soundId, bool repeat)
{
	this->_parentGame->pushDataPacket(PacketFactory::createSoundPacket(soundId, false, repeat));
}
