//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_MOJOJOGRAPHICS_HPP
#define RTYPE_MOJOJOGRAPHICS_HPP

#include "AGraphicsComponent.hpp"

class ResourcesLoader;

namespace Component {
	class MojojoGraphics : public AGraphicsComponent
	{
	public:
		explicit MojojoGraphics(Engine::Entity *parentEntity, ResourcesLoader *resourceLoader);
		~MojojoGraphics() override = default;

		void update() override;

		// handle methods
		void handleDeath(Engine::Mediator::Message messageType, AComponent *sender) noexcept;
		void handleHit(Engine::Mediator::Message messageType, AComponent *sender)noexcept;
		void handleMove(Engine::Mediator::Message, Engine::AComponent *sender) noexcept;

		AComponent *clone(Engine::Entity *parentEntity) const noexcept;
	};
}

#endif //RTYPE_MOJOJOGRAPHICS_HPP
