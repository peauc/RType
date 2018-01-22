//
// Created by romain on 12/01/18.
//

#include <iostream>
#include "Entity.hpp"

Engine::Entity::Entity() : _id(0), _active(false), _transformComponent(this), _components(),
						   _mediator(std::make_unique<Mediator>())
{
}

Engine::Entity::Entity(unsigned int id) : _id(id), _active(false), _transformComponent(this), _components(),
										  _mediator(std::make_unique<Mediator>())
{
}

void Engine::Entity::update() noexcept
{
	if (this->_active) {
		for (unsigned int i = 0; i < _components.size(); ++i) {
			this->_components[i]->update();
		}
	}
}

void Engine::Entity::executeCommands() noexcept
{
	for (unsigned int i = 0; i < _commands.size(); ++i) {
		std::cout << "before" << std::endl;
		this->_commands[i]->execute();
		std::cout << "after" << std::endl;
	}
	this->_commands.clear();
}

void Engine::Entity::receive(Engine::Mediator::Message messageType, Engine::AComponent *sender) noexcept
{
	if (this->_mediator != nullptr) {
		this->_mediator->send(messageType, sender);
	}
}

void Engine::Entity::addComponent(Engine::AComponent *component) noexcept
{
	this->_components.push_back(std::unique_ptr<AComponent>(component));
	component->registerToMediator(this->_mediator.get());
}

void Engine::Entity::addCommand(Engine::Commands::ICommand *command) noexcept
{
	this->_commands.push_back(std::unique_ptr<Commands::ICommand>(command));
}

Engine::Mediator &Engine::Entity::getMediator() noexcept
{
	return *_mediator;
}

const Engine::Mediator &Engine::Entity::getMediator() const noexcept
{
	return *_mediator;
}

Engine::TransformComponent &Engine::Entity::getTransformComponent() noexcept
{
	return _transformComponent;
}

const Engine::TransformComponent &Engine::Entity::getTransformComponent() const noexcept
{
	return _transformComponent;
}

void Engine::Entity::setId(unsigned int _id) noexcept
{
	this->_id = _id;
}

unsigned int Engine::Entity::getId() const noexcept
{
	return _id;
}

bool Engine::Entity::operator==(unsigned int id) noexcept
{
	return id == this->_id;
}

bool Engine::Entity::operator==(const Engine::Entity &other) noexcept
{
	return other._id == this->_id;
}

Engine::Entity *Engine::Entity::clone() noexcept
{
	Engine::Entity *newEntity = new Engine::Entity();

	newEntity->_transformComponent = this->_transformComponent;
	for (auto &component : this->_components) {
		newEntity->addComponent(component->clone(newEntity));
	}
	return newEntity;
}

bool Engine::Entity::isActive() const noexcept
{
	return _active;
}

void Engine::Entity::setActive(bool _active) noexcept
{
	Entity::_active = _active;
}
