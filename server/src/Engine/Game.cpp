//
// Created by romain on 12/01/18.
//

#include <Engine/Game.hpp>
#include <chrono>
#include <iostream>
#include <Factories/EntityFactory.hpp>

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

const std::vector<std::unique_ptr<Engine::Event>> &Engine::Game::getEvents() const
{
    return _events;
}

std::vector<std::unique_ptr<Engine::Event>> &Engine::Game::getEventsReference()
{
    return _events;
}


Engine::World &Engine::Game::getWorld()
{
	return *_world;
}

const Engine::World &Engine::Game::getWorld() const
{
	return *_world;
}

void Engine::Game::setWorld(std::unique_ptr<World> world)
{
	if (this->_world != nullptr) {
		this->_world->setParentGame(nullptr);
	}
	this->_world = std::move(world);
	this->_world->setParentGame(this);
}

