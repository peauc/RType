//
// Created by romain on 21/01/18.
//

#ifndef RTYPE_REMOVEENTITYCOMMAND_HPP
#define RTYPE_REMOVEENTITYCOMMAND_HPP

#include <Engine/World.hpp>
#include "ICommand.hpp"

namespace Engine::Commands {
	class RemoveEntityCommand : public ICommand
	{
	public:
		explicit RemoveEntityCommand(Engine::World &world, unsigned int entityId);
		~RemoveEntityCommand() = default;

		void execute() override;
	private:
		Engine::World &_world;
		unsigned int _entityId;
	};
}

#endif //RTYPE_REMOVEENTITYCOMMAND_HPP
