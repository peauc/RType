//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_ACOMPONENT_HPP
#define RTYPE_ACOMPONENT_HPP

#include <memory>
#include <unordered_map>
#include "Mediator.hpp"

namespace Engine {
	class Entity;

	class AComponent
	{
	public:
		explicit AComponent(Entity *parentEntity);
		virtual ~AComponent() = default;

		void registerToMediator(Mediator &mediator);
		void unregisterToMediator(Mediator &mediator);
		void receive(Mediator::Message messageType, AComponent *sender);

		virtual void update() = 0;

	protected:
		Entity *_parentEntity;
		std::vector<Mediator> _mediators;
		std::unordered_map<Mediator::Message, std::function<void(Mediator::Message, AComponent *)>> _validMessageTypes;
	};
}

#endif //RTYPE_ACOMPONENT_HPP
