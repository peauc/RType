//
// Created by romain on 17/01/18.
//

#ifndef RTYPE_DEFAULTCAMERAVIEWCOMPONENT_HPP
#define RTYPE_DEFAULTCAMERAVIEWCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include "AGraphicsComponent.hpp"

namespace Component {
	class DefaultCameraViewComponent : public Engine::AComponent
	{
	public:
		explicit DefaultCameraViewComponent(Engine::Entity *parentEntity, Engine::World *parentWorld);
		~DefaultCameraViewComponent() override = default;

		void update() override;
	private:
		Engine::World *_parentWorld;
		std::vector<Component::AGraphicsComponent *> _graphicComponents;
		Vector2d _relativeTopLeft;
		Vector2d _relativeBottomRight;
	};
}

#endif //RTYPE_DEFAULTCAMERAVIEWCOMPONENT_HPP