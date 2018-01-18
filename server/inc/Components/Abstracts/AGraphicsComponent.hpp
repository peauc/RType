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
		explicit AGraphicsComponent(Engine::Entity *parentEntity, RessourcesLoader *resourceLoader);
		~AGraphicsComponent() override = default;

		bool isInArea(float xPos, float yPos, float xRange, float yRange);
		float getRelativeXPos(float xPos, float xRange);
		float getRelativeYPos(float yPos, float yRange);

		RessourcesLoader *getResourceLoader() const;
		void setResourceLoader(RessourcesLoader *_resourceLoader);
		unsigned char getCurrentAnimationId() const;
		bool isHit() const;
		void setIsHit(bool isHit);
		bool isAlive() const;
		void setIsAlive(bool isAlive);
	protected:
		RessourcesLoader *_resourceLoader;
		std::vector<unsigned char> _animationIds;
		unsigned char _currentAnimationId;
		bool _isHit;
		bool _isAlive;
	};
}

#endif //RTYPE_AGRAPHICSCOMPONENT_HPP