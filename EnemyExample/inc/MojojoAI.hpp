//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_MOJOJOAI_HPP
#define RTYPE_MOJOJOAI_HPP

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
	class MojojoAI : public AInputComponent
	{
	public:
		explicit MojojoAI(Engine::Entity *parentEntity);
		~MojojoAI() override = default;

		void update() noexcept override;
		AComponent *clone(Engine::Entity *parentEntity) const noexcept override;
	};
}

#endif //RTYPE_MojojoAI_HPP
