//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_ENEMYPHYSICSCOMPONENT_HPP
#	define RTYPE_ENEMYPHYSICSCOMPONENT_HPP

#	include <Components/Abstracts/APhysicsComponent.hpp>

namespace Component {
	class EnemyPhysicsComponent : public APhysicsComponent
	{
	public:
		EnemyPhysicsComponent(Engine::Entity *parentEntity, Engine::Hitbox hitbox);
		~EnemyPhysicsComponent() override = default;

		void update() override;

		AComponent *clone(Engine::Entity *parentEntity) const noexcept;
	};
}

#endif //RTYPE_ENEMYPHYSICSCOMPONENT_HPP
