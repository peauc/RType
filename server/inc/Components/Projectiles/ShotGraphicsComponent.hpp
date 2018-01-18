//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_PLAYERSHOTGRAPHICSCOMPONENT_HPP
#define RTYPE_PLAYERSHOTGRAPHICSCOMPONENT_HPP

#include <RessourcesLoader.hpp>
#include <Components/Abstracts/AGraphicsComponent.hpp>

namespace Component {
	class ShotGraphicsComponent : public AGraphicsComponent
	{
	public:
		explicit ShotGraphicsComponent(Engine::Entity *parentEntity, unsigned char _travelAnimationId,
									   unsigned char _impactAnimationId);
		explicit ShotGraphicsComponent(Engine::Entity *parentEntity, RessourcesLoader *resourceLoader,
									   unsigned char _travelAnimationId, unsigned char _impactAnimationId);
		~ShotGraphicsComponent() override = default;

		void update() override;

		// handleMethod
		void handleImpact(Engine::Mediator::Message messageType, Engine::AComponent *sender);
	};
}

#endif //RTYPE_PLAYERSHOTGRAPHICSCOMPONENT_HPP
