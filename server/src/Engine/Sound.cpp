//
// Created by romain on 11/01/18.
//

#include <Engine/Sound.hpp>

Engine::Sound::Sound(unsigned int id, bool loop, bool music) : _id(id), _loop(loop), _music(music)
{
}

unsigned int Engine::Sound::getId() const
{
    return this->_id;
}

void Engine::Sound::setId(unsigned int _id)
{
    this->_id = _id;
}

bool Engine::Sound::isLoop() const
{
    return this->_loop;
}

void Engine::Sound::setLoop(bool _loop)
{
    this->_loop = _loop;
}

bool Engine::Sound::isMusic() const
{
    return this->_music;
}

void Engine::Sound::setMusic(bool _music)
{
    this->_music = _music;
}

