//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_WORLD_HPP
#define RTYPE_WORLD_HPP

#include <list>
#include <queue>
#include "Entity.hpp"
#include "Mediator.hpp"
#include "Sound.hpp"

namespace Engine {
    class World {
        std::list<Entity> _objects;
        std::vector<std::shared_ptr<Mediator>> _mediators;
        std::queue<Sound> _sounds;

    public:
        World() = default;
        ~World() = default;

        World(const World &) = delete;
        const World &operator=(const World &) = delete;

        void addObject(const Entity &entity);
        void removeObject(const Entity &entity);

        void update();
    };
}

#endif //RTYPE_WORLD_HPP
