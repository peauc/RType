//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_MojojoPhysics_HPP
#	define RTYPE_MojojoPhysics_HPP

#	include <Components/Abstracts/APhysicsComponent.hpp>

namespace Component {
	class MojojoPhysics : public APhysicsComponent
	{
	public:
		MojojoPhysics(Engine::Entity *parentEntity, Engine::Hitbox hitbox);
		~MojojoPhysics() override = default;

		void update() override;

		AComponent *clone(Engine::Entity *parentEntity) const noexcept;
	};
}

#endif //RTYPE_MojojoPhysics_HPP
