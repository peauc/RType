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
		AGraphicsComponent(Engine::Entity *parentEntity);
		explicit AGraphicsComponent(Engine::Entity *parentEntity, RessourcesLoader *resourceLoader);
		~AGraphicsComponent() override = default;

		bool isInArea(float xPos, float yPos, float xRange, float yRange);
		RessourcesLoader *getResourceLoader() const;
		void setResourceLoader(RessourcesLoader *_resourceLoader);
	protected:
		RessourcesLoader *_resourceLoader;
		std::vector<unsigned int> _animationIds;
		unsigned int _currentAnimationId;
	};
}

#endif //RTYPE_AGRAPHICSCOMPONENT_HPP