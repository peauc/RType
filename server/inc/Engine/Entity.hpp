//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_ENTITY_HPP
#define RTYPE_ENTITY_HPP

#include <vector>
#include <memory>
#include "ICommand.hpp"
#include "AComponent.hpp"
#include "TransformComponent.hpp"
#include "Observer.hpp"

namespace Engine {
	class Entity : public Observer
	{
	public:
		Entity();
		explicit Entity(unsigned int id);
		~Entity() override = default;

		void update() noexcept;
		void executeCommands() noexcept;
		void receive(Mediator::Message messageType, AComponent *sender) noexcept override;
		void addComponent(AComponent *component) noexcept;
		void addCommand(Commands::ICommand *command) noexcept;
		Mediator &getMediator() noexcept;
		const Mediator &getMediator() const noexcept;
		TransformComponent &getTransformComponent() noexcept;
		const TransformComponent &getTransformComponent() const noexcept;
		void setId(unsigned int id) noexcept;
		unsigned int getId() const noexcept;
		bool isActive() const noexcept;
		void setActive(bool active) noexcept;

		bool operator==(unsigned int id) noexcept;
		bool operator==(const Entity &other) noexcept;
		Entity *clone() noexcept;

	private:
		unsigned int _id;
		bool _active;
		TransformComponent _transformComponent;
		std::vector<std::unique_ptr<AComponent>> _components;
		std::vector<std::unique_ptr<Commands::ICommand>> _commands;
		std::unique_ptr<Mediator> _mediator;
	};
}

#endif //RTYPE_ENTITY_HPP
