//
// Created by romain on 16/01/18.
//

#ifndef RTYPE_AGRAPHICSCOMPONENT_HPP
#define RTYPE_AGRAPHICSCOMPONENT_HPP

#include <Engine/AComponent.hpp>
#include <Engine/Game.hpp>

namespace Component {
	class AGraphicsComponent : public Engine::AComponent
	{
	public:
		explicit AGraphicsComponent(Engine::Entity *parentEntity);
		~AGraphicsComponent() override = default;

		bool isInArea(float xPos, float yPos, float xRange, float yRange);
	};
}

#endif //RTYPE_AGRAPHICSCOMPONENT_HPP