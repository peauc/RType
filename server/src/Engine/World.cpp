//
// Created by romain on 12/01/18.
//

#include "Entity.hpp"
#include "World.hpp"

Engine::World::World() : _nextEntityId(0), _parentGame(nullptr)
{
}

unsigned int Engine::World::addObject(Engine::Entity *(*call)(unsigned int, Engine::Game &)) noexcept
{
	this->_objects.push_back(std::unique_ptr<Entity>(call(this->_nextEntityId, *this->_parentGame)));
	this->_nextEntityId++;
	return this->_nextEntityId - 1;
}

unsigned int Engine::World::addObject(std::unique_ptr<Entity> entity) noexcept
{
	if (entity->getId() == 0) {
		entity->setId(this->_nextEntityId);
		this->_nextEntityId++;
	}
	this->_objects.push_back(std::move(entity));
	return this->_objects.back()->getId();
}

void Engine::World::removeObject(unsigned int id) noexcept
{
	this->_objects.erase(std::find_if(this->_objects.begin(), this->_objects.end(),
									  [&](const std::unique_ptr<Entity> &entity) { return entity->getId() == id; }));
}

Engine::Game *Engine::World::getParentGame() const noexcept
{
	return _parentGame;
}

void Engine::World::setParentGame(Engine::Game *_parentGame) noexcept
{
	World::_parentGame = _parentGame;
}

std::unique_ptr<Engine::Entity> &Engine::World::getCamera() noexcept
{
	return _camera;
}

void Engine::World::setCamera(std::unique_ptr<Engine::Entity> camera) noexcept
{
	this->_camera = std::move(camera);
}

void Engine::World::update() noexcept
{
	for (std::list<std::unique_ptr<Entity>>::const_iterator it = this->_objects.begin();
		 it != this->_objects.end(); it++) {
		(*it)->update();
	}
	if (this->_camera != nullptr) {
		this->_camera->update();
	}
}

std::unique_ptr<Engine::Mediator> &Engine::World::getMediator() noexcept
{
	return _mediator;
}

const std::unique_ptr<Engine::Mediator> &Engine::World::getMediator() const noexcept
{
	return _mediator;
}

void Engine::World::addMediator() noexcept
{
	this->_mediator = std::make_unique<Engine::Mediator>();
}

const std::list<std::unique_ptr<Engine::Entity>> &Engine::World::getObjects() const noexcept
{
	return _objects;
}
