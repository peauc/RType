//
// Created by romain on 21/01/18.
//

#include "Entity.hpp"
#include "Game.hpp"
#include "Zone.hpp"
#include "Hitbox.hpp"
#include "ZoneComponent.hpp"

Engine::MapLoader::Zone::Zone(const Vector2d &topLeftCoords, const Vector2d &bottomRightCoords)
{
	this->_topLeftCoords = topLeftCoords;
	this->_bottomRightCoords = bottomRightCoords;
}

void Engine::MapLoader::Zone::createZone(Game &game) const
{
	Engine::Entity *zone = new Engine::Entity(0);

	Component::ZoneComponent *zoneComponent = new Component::ZoneComponent(zone,
																		   Engine::Hitbox(Engine::Hitbox::ZONE,
																						  Vector2d(0, 0),
																						  Vector2d(
																								  this->_bottomRightCoords.x -
																								  this->_topLeftCoords.x,
																								  this->_bottomRightCoords.y -
																								  this->_topLeftCoords.y)),
																		   game.getWorld().get());

	for (const auto &entity : this->_zoneObjects) {
		zoneComponent->addEntity(std::unique_ptr<Entity>(entity.createEntity(game)));
	}

	zone->addComponent(zoneComponent);
	if (game.getWorld()->getMediator() != nullptr) {
		zoneComponent->registerToMediator(game.getWorld()->getMediator().get());
	}
	zone->setActive(true);

	game.getWorld()->addObject(std::unique_ptr<Entity>(zone));
}

void Engine::MapLoader::Zone::addZoneObject(
		const Engine::MapLoader::Zone::ZoneObject &zoneObject) {
	this->_zoneObjects.push_back(zoneObject);
}

const Vector2d &Engine::MapLoader::Zone::getTopLeftCoords() const {
	return (this->_topLeftCoords);
}

const Vector2d &Engine::MapLoader::Zone::getBotRightCoords() const {
	return (this->_bottomRightCoords);
}

const std::vector<Engine::MapLoader::Zone::ZoneObject> &
Engine::MapLoader::Zone::getZoneObjects() const {
	return (this->_zoneObjects);
}

Engine::MapLoader::Zone::ZoneObject::ZoneObject(const std::string &libname, const Vector2d &pos) : _libname(libname),
																								   _pos(pos)
{
}

Engine::Entity *Engine::MapLoader::Zone::ZoneObject::createEntity(Engine::Game &game) const
{
	return game.cloneEntity(this->_libname);
}
