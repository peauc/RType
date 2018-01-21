//
// Created by romain on 17/01/18.
//

#ifndef RTYPE_DEFAULTCAMERAVIEWCOMPONENT_HPP
#define RTYPE_DEFAULTCAMERAVIEWCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include "Components/Abstracts/AGraphicsComponent.hpp"

namespace Component {
	class CameraViewComponent : public Engine::AComponent
	{
	public:
		explicit CameraViewComponent(Engine::Entity *parentEntity, Engine::Game *parentGame);
		~CameraViewComponent() override = default;

		void update() noexcept override;
		const Vector2d &getRelativeBottomRight() const noexcept;

		// handle methods
		void handleGraphicsRegistration(Engine::Mediator::Message messageType, AComponent *sender) noexcept;
	private:
		Engine::Game *_parentGame;
		std::vector<Component::AGraphicsComponent *> _graphicComponents;
		Vector2d _relativeTopLeft;
		Vector2d _relativeBottomRight;
	};
}

#endif //RTYPE_DEFAULTCAMERAVIEWCOMPONENT_HPP