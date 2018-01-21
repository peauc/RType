//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_PLAYERSHOTAUDIOCOMPONENT_HPP
#define RTYPE_PLAYERSHOTAUDIOCOMPONENT_HPP

#include <Components/Abstracts/AAudioComponent.hpp>

namespace Component {
	class ShotAudioComponent : public AAudioComponent
	{
	public:
		ShotAudioComponent(Engine::Entity *parentEntity, Engine::Game *parentGame, unsigned char impactSoundId);
		~ShotAudioComponent() override = default;

		void update() override;

		// handleMethod
		void handleImpact(Engine::Mediator::Message messageType, Engine::AComponent *sender);

		AComponent *clone(Engine::Entity *parentEntity) const override;
	};
}

#endif //RTYPE_PLAYERSHOTAUDIOCOMPONENT_HPP
