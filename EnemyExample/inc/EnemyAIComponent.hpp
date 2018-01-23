//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_ENEMYAICOMPONENT_HPP
#define RTYPE_ENEMYAICOMPONENT_HPP

#	include <queue>
#	include <utility>
#	include "AInputComponent.hpp"
#	include "AComponent.hpp"
#	include "Event.hpp"

namespace Component {
	class AInputComponent;
}

namespace Engine {
	class AComponent;
	class Entity;
}

namespace Component {
	class EnemyAIComponent : public AInputComponent
	{
	public:
		explicit EnemyAIComponent(Engine::Entity *parentEntity);
		~EnemyAIComponent() override = default;

		void update() noexcept override;
		AComponent *clone(Engine::Entity *parentEntity) const noexcept override;
	};
}

#endif //RTYPE_ENEMYAICOMPONENT_HPP
