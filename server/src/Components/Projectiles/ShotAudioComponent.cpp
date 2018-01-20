//
// Created by romain on 19/01/18.
//

#include <Engine/Entity.hpp>
#include <Engine/World.hpp>
#include <Components/Projectiles/ShotAudioComponent.hpp>

Component::ShotAudioComponent::ShotAudioComponent(Engine::Entity *parentEntity, Engine::World *parentWorld,
												  unsigned char impactSoundId) :
		AAudioComponent(parentEntity, parentWorld)
{
	this->_validMessageTypes[Engine::Mediator::Message::DEATH] = std::bind(&ShotAudioComponent::handleImpact,
																		   this, std::placeholders::_1,
																		   std::placeholders::_2);
}

void Component::ShotAudioComponent::update()
{
}

void Component::ShotAudioComponent::handleImpact(Engine::Mediator::Message messageType, Engine::AComponent *sender)
{
	this->addSoundPacket(this->_soundIds[0], false);
}
