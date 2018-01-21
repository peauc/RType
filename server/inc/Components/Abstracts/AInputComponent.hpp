//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_AINPUTCOMPONENT_HPP
#define RTYPE_AINPUTCOMPONENT_HPP

#include "Entity.hpp"
#include "Event.hpp"

namespace Component {
	class AInputComponent : public Engine::AComponent
	{
	public:
		explicit AInputComponent(Engine::Entity *parentEntity);
		~AInputComponent() override = default;

		const Engine::Event &getEvent() const noexcept;
		bool hasEvent() const noexcept;

		AInputComponent &operator=(const AInputComponent &other) noexcept;
	protected:
		std::unique_ptr<Engine::Event> _event;
	};
}

#endif //RTYPE_AINPUTCOMPONENT_HPP
