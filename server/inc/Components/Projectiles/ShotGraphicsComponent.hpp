//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_PLAYERSHOTGRAPHICSCOMPONENT_HPP
#define RTYPE_PLAYERSHOTGRAPHICSCOMPONENT_HPP

#include "ResourcesLoader.hpp"
#include "AGraphicsComponent.hpp"

namespace Component {
	class ShotGraphicsComponent : public AGraphicsComponent
	{
	public:
		explicit ShotGraphicsComponent(Engine::Entity *parentEntity, ResourcesLoader *resourceLoader,
									   unsigned char _travelAnimationId, unsigned char _impactAnimationId);
		~ShotGraphicsComponent() override = default;

		void update() noexcept override;

		// handleMethod
		void handleImpact(Engine::Mediator::Message messageType, Engine::AComponent *sender) noexcept;

		AComponent *clone(Engine::Entity *parentEntity) const noexcept override;
	};
}

#endif //RTYPE_PLAYERSHOTGRAPHICSCOMPONENT_HPP
