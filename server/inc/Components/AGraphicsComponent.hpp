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
		explicit AGraphicsComponent(Engine::Entity *parentEntity, Engine::Game *parentGame);
		~AGraphicsComponent() override;
	private:
		Engine::Game *_parentGame;
	};
}

#endif //RTYPE_AGRAPHICSCOMPONENT_HPP
