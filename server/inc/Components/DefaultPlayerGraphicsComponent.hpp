//
// Created by romain on 17/01/18.
//

#ifndef RTYPE_DEFAULTPLAYERGRAPHICSCOMPONENT_HPP
#define RTYPE_DEFAULTPLAYERGRAPHICSCOMPONENT_HPP

#include "AGraphicsComponent.hpp"

namespace Component {
	class DefaultPlayerGraphicsComponent : public AGraphicsComponent
	{
	public:
		explicit DefaultPlayerGraphicsComponent(Engine::Entity *parentEntity);
		~DefaultPlayerGraphicsComponent() override = default;

		void update() override;
	};
}

#endif //RTYPE_DEFAULTPLAYERGRAPHICSCOMPONENT_HPP
