//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_ACOMPONENT_HPP
#define RTYPE_ACOMPONENT_HPP

#include <memory>
#include <unordered_map>
#include "Mediator.hpp"
#include "Observer.hpp"

namespace Engine {
	class Entity;

	class AComponent : Observer
	{
	public:
		explicit AComponent(Entity *parentEntity);
		explicit AComponent(const AComponent &other, Entity *parentEntity);
		virtual ~AComponent() = default;

		AComponent &operator=(const AComponent &other) noexcept ;

		void registerToMediator(Mediator *mediator) noexcept ;
		void unregisterToMediator(Mediator *mediator) noexcept ;
		void receive(Mediator::Message messageType, AComponent *sender) noexcept  override;
		void sendToAll(Mediator::Message messageType) noexcept ;
		void addObserver(Observer *) noexcept ;
		void removeObserver(Observer *) noexcept ;
		unsigned int getParentEntityId() const noexcept ;
		bool isParentActive() const noexcept ;

		virtual void update() = 0;

		virtual AComponent *clone(Entity *parentEntity) const noexcept ;

	protected:
		Entity *_parentEntity;
		std::vector<Mediator *> _mediators;
		std::vector<Observer *> _observers;

		std::unordered_map<Mediator::Message, std::function<void(Mediator::Message, AComponent *)>> _validMessageTypes;
	};
}

#endif //RTYPE_ACOMPONENT_HPP
