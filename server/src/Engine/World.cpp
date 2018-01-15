//
// Created by romain on 12/01/18.
//

#include <Engine/Entity.hpp>
#include <Engine/World.hpp>

void Engine::World::addObject(std::unique_ptr<Entity> &&entity)
{
    this->_objects.push_back(std::move(entity));
}

void Engine::World::removeObject(unsigned int id)
{
    this->_objects.erase(std::find_if(this->_objects.begin(), this->_objects.end(),
                                      [&](const std::unique_ptr<Entity> &entity) { return entity->getId() == id; }));
}

void Engine::World::update()
{
    for (std::list<std::unique_ptr<Entity>>::const_iterator it = this->_objects.begin();
         it != this->_objects.end(); it++) {
        (*it)->update();
    }
}
