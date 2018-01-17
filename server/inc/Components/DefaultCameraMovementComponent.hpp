//
// Created by romain on 16/01/18.
//

#ifndef RTYPE_DEFAULTCAMERAMOVEMENTCOMPONENT_HPP
#define RTYPE_DEFAULTCAMERAMOVEMENTCOMPONENT_HPP

#include <Engine/Game.hpp>
#include "AMovementComponent.hpp"

namespace Component {
	class DefaultCameraMovementComponent : public AMovementComponent
	{
	public:
		explicit DefaultCameraMovementComponent(Engine::Entity *parentEntity, Engine::Game *parentGame);
		~DefaultCameraMovementComponent() override = default;

		void update() override;
	private:
		Engine::Game *_parentGame;
	};
}

#endif //RTYPE_DEFAULTCAMERAMOVEMENTCOMPONENT_HPP
