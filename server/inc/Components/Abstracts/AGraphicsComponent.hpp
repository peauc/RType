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

		bool isInArea(double xPos, double yPos, double xRange, double yRange) noexcept;
		double getRelativeXPos(double xPos, double xRange) noexcept;
		double getRelativeYPos(double yPos, double yRange) noexcept;
		RessourcesLoader *getResourceLoader() const noexcept;
		void setResourceLoader(RessourcesLoader *_resourceLoader) noexcept;
		unsigned char getCurrentAnimationId() const noexcept;
		bool isHit() const noexcept;
		void setIsHit(bool isHit) noexcept;
		bool isAlive() const noexcept;
		void setIsAlive(bool isAlive) noexcept;
		const Vector2d &getRelativeStartPos() const noexcept;
		const Vector2d &getRange() const noexcept;
		void setHitbox();

		// operator overloads
		AGraphicsComponent &operator=(const AGraphicsComponent &other) noexcept;
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