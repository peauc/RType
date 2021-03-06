//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_PLAYERSHOTMOVEMENTCOMPONENT_HPP
#define RTYPE_PLAYERSHOTMOVEMENTCOMPONENT_HPP

#include <cmath>
#include "AMovementComponent.hpp"

namespace Component {
	class ShotMovementComponent : public AMovementComponent
	{
	public:
		explicit ShotMovementComponent(Engine::Entity *parentEntity, double speed, unsigned int lifetime);
		~ShotMovementComponent() override = default;

		void update() noexcept override;

		AComponent *clone(Engine::Entity *parentEntity) const noexcept override;
	private:
		double _speed;
		unsigned int _lifetime;
	};
}

#endif //RTYPE_PLAYERSHOTMOVEMENTCOMPONENT_HPP
