//
// Created by romain on 17/01/18.
//

#ifndef RTYPE_DEFAULTPLAYERGRAPHICSCOMPONENT_HPP
#define RTYPE_DEFAULTPLAYERGRAPHICSCOMPONENT_HPP

#include "Components/Abstracts/AGraphicsComponent.hpp"

namespace Component {
	class PlayerGraphicsComponent : public AGraphicsComponent
	{
	public:
		explicit PlayerGraphicsComponent(Engine::Entity *parentEntity, RessourcesLoader *resourceLoader);
		~PlayerGraphicsComponent() override = default;

		void update() override;

		// handle methods
		void handleDeath(Engine::Mediator::Message messageType, AComponent *sender);
		void handleHit(Engine::Mediator::Message messageType, AComponent *sender);
		void handleMove(Engine::Mediator::Message messageType, AComponent *sender);

		AComponent *clone(Engine::Entity *parentEntity) const override;
	};
}

#endif //RTYPE_DEFAULTPLAYERGRAPHICSCOMPONENT_HPP
