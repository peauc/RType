//
// Created by romain on 12/01/18.
//

#include <Engine/Game.hpp>
#include <chrono>
#include <iostream>

Engine::Game::Game()
{
    this->_world = std::make_unique<World>();
}

Engine::Game::~Game()
= default;

void Engine::Game::run()
{
    std::chrono::time_point<std::chrono::system_clock> previous = std::chrono::system_clock::now();
    double lag = 0;

    while (!this->_stop) {
        std::chrono::time_point<std::chrono::system_clock> current = std::chrono::system_clock::now();
        double elapsed = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>
                (current - previous).count());
        previous = current;
        lag += elapsed;

        // PROCESS INPUT
        while (lag > MS_PER_UPDATE) {
            this->_world->update();
            lag -= MS_PER_UPDATE;
        }
        // SEND INFORMATIONS TO CLIENT
    }
}
