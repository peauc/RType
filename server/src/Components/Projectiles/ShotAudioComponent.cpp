//
// Created by romain on 19/01/18.
//

#include "Entity.hpp"
#include "World.hpp"
#include "ShotAudioComponent.hpp"

Component::ShotAudioComponent::ShotAudioComponent(Engine::Entity *parentEntity, Engine::Game *parentGame,
												  unsigned char) :
		AAudioComponent(parentEntity, parentGame)
{
	this->_validMessageTypes[Engine::Mediator::Message::DEATH] = std::bind(&ShotAudioComponent::handleImpact,
																		   this, std::placeholders::_1,
																		   std::placeholders::_2);
}

void Component::ShotAudioComponent::update() noexcept
{
}

void Component::ShotAudioComponent::handleImpact(Engine::Mediator::Message, Engine::AComponent *) noexcept
{
	//this->addSoundPacket(this->_soundIds[0], false);
}

Engine::AComponent *Component::ShotAudioComponent::clone(Engine::Entity *parentEntity) const noexcept
{
	ShotAudioComponent *newComp = new ShotAudioComponent(parentEntity, this->_parentGame, 0);

	*newComp = *this;

	return newComp;
}
