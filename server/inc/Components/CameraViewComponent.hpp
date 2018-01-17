//
// Created by romain on 17/01/18.
//

#ifndef RTYPE_DEFAULTCAMERAVIEWCOMPONENT_HPP
#define RTYPE_DEFAULTCAMERAVIEWCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include "AGraphicsComponent.hpp"

namespace Component {
	class CameraViewComponent : public Engine::AComponent
	{
	public:
		explicit CameraViewComponent(Engine::Entity *parentEntity, Engine::World *parentWorld);
		~CameraViewComponent() override = default;

		void update() override;

		// handle methods
		void handleGraphicsRegistration(Engine::Mediator::Message messageType, AComponent *sender);
	private:
		Engine::World *_parentWorld;
		std::vector<Component::AGraphicsComponent *> _graphicComponents;
		Vector2d _relativeTopLeft;
		Vector2d _relativeBottomRight;
	};
}

#endif //RTYPE_DEFAULTCAMERAVIEWCOMPONENT_HPP