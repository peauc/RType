//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_ENEMYAICOMPONENT_HPP
#define RTYPE_ENEMYAICOMPONENT_HPP

#	include <Engine/AComponent.hpp>
#	include <Engine/Event.hpp>
#	include <queue>
#	include <utility>
#	include "AAIComponent.hpp"

namespace Component {
	class EnemyAIComponent : public AAIComponent
	{
	public:
		explicit EnemyAIComponent(Engine::Entity *parentEntity,
									  std::vector<std::unique_ptr<Engine::Event>> &gameEvents);
		~EnemyAIComponent() = default;

		void update();
	private:
		std::vector<std::unique_ptr<Engine::Event>> &_gameEvents;
	};
}

#endif //RTYPE_ENEMYAICOMPONENT_HPP
