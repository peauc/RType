//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_GAME_HPP
#define RTYPE_GAME_HPP

#include <queue>
#include "World.hpp"
#include "Event.hpp"

#define MS_PER_UPDATE 16

namespace Engine {
    class Game
    {
        std::unique_ptr<World> _world;
        std::vector<std::unique_ptr<Event>> _events;
        bool _stop;

    public:
        Game();
        ~Game();
        void run();

        std::vector<std::unique_ptr<Event>> &getEventsReference();
        const std::vector<std::unique_ptr<Event>> &getEvents() const;
    };
}

#endif //RTYPE_GAME_HPP
