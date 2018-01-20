//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_AMOVEMENTCOMPONENT_HPP
#define RTYPE_AMOVEMENTCOMPONENT_HPP

#include <Engine/Entity.hpp>
#include <Engine/AComponent.hpp>
#include <Engine/Event.hpp>

namespace Component {
	class AMovementComponent : public Engine::AComponent
	{
	public:
		explicit AMovementComponent(Engine::Entity *parentEntity);
		~AMovementComponent() override = default;
	protected:
		std::unique_ptr<Engine::Event> _event;
	};
}

#endif //RTYPE_AMOVEMENTCOMPONENT_HPP
