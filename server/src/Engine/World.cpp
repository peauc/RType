//
// Created by romain on 12/01/18.
//

#include <Engine/Entity.hpp>
#include <Engine/World.hpp>

void Engine::World::addObject(const Entity &entity)
{
    this->_objects.push_back(entity);
}

void Engine::World::removeObject(const Engine::Entity &entity)
{
    this->_objects.erase(std::find(this->_objects.begin(), this->_objects.end(), entity));
}

void Engine::World::update()
{
    for (Entity entity : this->_objects) {
        entity.update();
    }
}
