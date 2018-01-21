//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_ENEMYGRAPHICSCOMPONENT_HPP
#define RTYPE_ENEMYGRAPHICSCOMPONENT_HPP

#include "Components/Abstracts/AGraphicsComponent.hpp"

namespace Component {
	class EnemyGraphicsComponent : public AGraphicsComponent
	{
	public:
		explicit EnemyGraphicsComponent(Engine::Entity *parentEntity, RessourcesLoader *resourceLoader);
		~EnemyGraphicsComponent() override = default;

		void update() override;

		// handle methods
		void handleDeath(Engine::Mediator::Message messageType, AComponent *sender);
		void handleHit(Engine::Mediator::Message messageType, AComponent *sender);
	};
}

#endif //RTYPE_ENEMYGRAPHICSCOMPONENT_HPP
