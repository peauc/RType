//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_ENTITY_HPP
#define RTYPE_ENTITY_HPP

#include <vector>
#include <memory>
#include <Engine/Commands/ICommand.hpp>
#include "AComponent.hpp"
#include "TransformComponent.hpp"

namespace Engine {
	class Entity
	{
	public:
		explicit Entity(unsigned int id);
		~Entity() = default;

		void update();
		void executeCommands();
		void receive(Mediator::Message messageType, AComponent *sender);

		void addComponent(AComponent *component);
		void addCommand(Commands::ICommand *command);

		Mediator &getMediator();
		const Mediator &getMediator() const;
		TransformComponent &getTransformComponent();
		const TransformComponent &getTransformComponent() const;
		const unsigned int getId() const;

		bool operator==(unsigned int id);
		bool operator==(const Entity &other);

	private:
		unsigned int _id;
		TransformComponent _transformComponent;
		std::vector<std::unique_ptr<AComponent>> _components;
		std::vector<std::unique_ptr<Commands::ICommand>> _commands;
		std::unique_ptr<Mediator> _mediator;
	};
}

#endif //RTYPE_ENTITY_HPP
