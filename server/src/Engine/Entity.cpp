//
// Created by romain on 12/01/18.
//

#include <Engine/Entity.hpp>

Engine::Entity::Entity(unsigned int id) : _id(id), _transformComponent(this), _components(),
										  _mediator(std::make_unique<Mediator>())
{
}

void Engine::Entity::update()
{
	for (int i = 0; i < _components.size(); ++i) {
		this->_components[i]->update();
	}
}

void Engine::Entity::executeCommands()
{
	for (int i = 0; i < _commands.size(); ++i) {
		this->_commands[i]->execute();
	}
	this->_commands.clear();
}

void Engine::Entity::receive(Engine::Mediator::Message messageType, Engine::AComponent *sender)
{
	if (this->_mediator != nullptr) {
		this->_mediator->send(messageType, sender);
	}
}

void Engine::Entity::addComponent(Engine::AComponent *component)
{
	this->_components.push_back(std::unique_ptr<AComponent>(component));
	component->registerToMediator(this->_mediator.get());
}

void Engine::Entity::addCommand(Engine::Commands::ICommand *command)
{
	this->_commands.push_back(std::unique_ptr<Commands::ICommand>(command));
}

Engine::Mediator &Engine::Entity::getMediator()
{
	return *_mediator;
}

const Engine::Mediator &Engine::Entity::getMediator() const
{
	return *_mediator;
}

Engine::TransformComponent &Engine::Entity::getTransformComponent()
{
	return _transformComponent;
}

const Engine::TransformComponent &Engine::Entity::getTransformComponent() const
{
	return _transformComponent;
}

const unsigned int Engine::Entity::getId() const
{
	return _id;
}

bool Engine::Entity::operator==(unsigned int id)
{
	return id == this->_id;
}

bool Engine::Entity::operator==(const Engine::Entity &other)
{
	return other._id == this->_id;
}