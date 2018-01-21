//
// Created by romain on 15/01/18.
//

#include "Event.hpp"

Engine::Event::Event(unsigned int entityId) :
        _entityId(entityId),
        _xVelocity(0),
        _yVelocity(0),
        _shotReleased(false),
        _chargingShot(false)
{
}