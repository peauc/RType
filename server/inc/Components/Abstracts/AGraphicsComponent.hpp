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
		explicit AGraphicsComponent(Engine::Entity *parentEntity, RessourcesLoader *resourceLoader);
		~AGraphicsComponent() override = default;

		bool isInArea(double xPos, double yPos, double xRange, double yRange);
		double getRelativeXPos(double xPos, double xRange);
		double getRelativeYPos(double yPos, double yRange);

		RessourcesLoader *getResourceLoader() const;
		void setResourceLoader(RessourcesLoader *_resourceLoader);
		unsigned char getCurrentAnimationId() const;
		bool isHit() const;
		void setIsHit(bool isHit);
		bool isAlive() const;
		void setIsAlive(bool isAlive);
		const Vector2d &getRelativeStartPos() const;
		const Vector2d &getRange() const;

		AGraphicsComponent &operator=(const AGraphicsComponent &other);
	protected:
		RessourcesLoader *_resourceLoader;
		std::vector<unsigned char> _animationIds;
		unsigned char _currentAnimationId;
		Vector2d _relativeStartPos;
		Vector2d _relativeRange;

		bool _isHit;
		bool _isAlive;
	};
}

#endif //RTYPE_AGRAPHICSCOMPONENT_HPP