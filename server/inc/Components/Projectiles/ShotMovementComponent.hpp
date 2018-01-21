//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_PLAYERSHOTMOVEMENTCOMPONENT_HPP
#define RTYPE_PLAYERSHOTMOVEMENTCOMPONENT_HPP

#include <cmath>
#include "Components/Abstracts/AMovementComponent.hpp"

namespace Component {
	class ShotMovementComponent : public AMovementComponent
	{
	public:
		explicit ShotMovementComponent(Engine::Entity *parentEntity, double speed);
		~ShotMovementComponent() override = default;

		void update() noexcept override;

		AComponent *clone(Engine::Entity *parentEntity) const noexcept override;
	private:
		double _speed;
	};
}

#endif //RTYPE_PLAYERSHOTMOVEMENTCOMPONENT_HPP
