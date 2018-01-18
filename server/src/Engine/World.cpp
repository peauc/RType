//
// Created by romain on 12/01/18.
//

#include <Engine/Entity.hpp>
#include <Engine/World.hpp>

Engine::World::World() : _nextEntityId(0), _parentGame(nullptr)
{
}

unsigned int Engine::World::addObject(Engine::Entity *(*call)(unsigned int, Engine::Game &))
{
	this->_objects.push_back(std::unique_ptr<Entity>(call(this->_nextEntityId, *this->_parentGame)));
	this->_nextEntityId++;
	return this->_nextEntityId - 1;
}

unsigned int Engine::World::addObject(std::unique_ptr<Entity> entity)
{
	this->_objects.push_back(std::move(entity));
	return this->_objects.end()->get()->getId();
}

void Engine::World::removeObject(unsigned int id)
{
	this->_objects.erase(std::find_if(this->_objects.begin(), this->_objects.end(),
									  [&](const std::unique_ptr<Entity> &entity) { return entity->getId() == id; }));
}

Engine::Game *Engine::World::getParentGame() const
{
	return _parentGame;
}

void Engine::World::setParentGame(Engine::Game *_parentGame)
{
	World::_parentGame = _parentGame;
}

std::unique_ptr<Engine::Entity> &Engine::World::getCamera()
{
	return _camera;
}

void Engine::World::setCamera(std::unique_ptr<Engine::Entity> camera)
{
	this->_camera = std::move(camera);
}

void Engine::World::update()
{
	for (std::list<std::unique_ptr<Entity>>::const_iterator it = this->_objects.begin();
		 it != this->_objects.end(); it++) {
		(*it)->update();
	}
	if (this->_camera != nullptr) {
		this->_camera->update();
	}
}

std::unique_ptr<Engine::Mediator> &Engine::World::getMediator()
{
	return _mediator;
}

const std::unique_ptr<Engine::Mediator> &Engine::World::getMediator() const
{
	return _mediator;
}

void Engine::World::setMediator(std::unique_ptr<Engine::Mediator> mediator)
{
	this->_mediator = std::move(mediator);
}

void Engine::World::addPacketToSend(Packet::DataPacket *packet)
{
	this->_packetsToSend.push_back(std::unique_ptr<Packet::DataPacket>(packet));
}

const std::vector<std::unique_ptr<Packet::DataPacket>> &Engine::World::getPacketsToSend() const
{
	return this->_packetsToSend;
}

void Engine::World::emptyPacketsToSend()
{
	this->_packetsToSend.clear();
}