//
// Created by romain on 18/01/18.
//

#include <Components/Abstracts/AAudioComponent.hpp>
#include <Factories/PacketFactory.hpp>

Component::AAudioComponent::AAudioComponent(Engine::Entity *parentEntity, Engine::World *parentWorld) :
		AComponent(parentEntity), _parentWorld(parentWorld)
{
}

void Component::AAudioComponent::addSoundPacket(unsigned char soundId, bool repeat)
{
	this->_parentWorld->addPacketToSend(PacketFactory::createSoundPacket(soundId, false, repeat));
}
