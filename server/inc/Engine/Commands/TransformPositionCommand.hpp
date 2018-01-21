//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_TRANSFORMPOSITIONCOMMAND_HPP
#define RTYPE_TRANSFORMPOSITIONCOMMAND_HPP

#include "Engine/TransformComponent.hpp"
#include "ICommand.hpp"

namespace Engine::Commands {
	class TransformPositionCommand : public ICommand
	{
	public:
		explicit TransformPositionCommand(Engine::TransformComponent &transformComponent, double x, double y);
		~TransformPositionCommand() = default;

		void execute() noexcept override;

	private:
		Engine::TransformComponent &_transformComponent;
		double _x;
		double _y;
	};
}

#endif //RTYPE_TRANSFORMPOSITIONCOMMAND_HPP
