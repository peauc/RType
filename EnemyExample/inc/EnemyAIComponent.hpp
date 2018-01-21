//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_ENEMYAICOMPONENT_HPP
#define RTYPE_ENEMYAICOMPONENT_HPP

#	include <queue>
#	include <utility>
#	include "AComponent.hpp"
#	include "Event.hpp"
#	include "Abstracts/AInputComponent.hpp"

namespace Component {
	class EnemyAIComponent : public AInputComponent
	{
	public:
		explicit EnemyAIComponent(Engine::Entity *parentEntity);
		~EnemyAIComponent() = default;

		void update();
	private:
		std::vector<std::unique_ptr<Engine::Event>> _gameEvents;
	};
}

#endif //RTYPE_ENEMYAICOMPONENT_HPP
