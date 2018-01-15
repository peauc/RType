//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_EVENT_HPP
#define RTYPE_EVENT_HPP

namespace Engine {
    struct Event
    {
        unsigned int _entityId;
        float _xVelocity;
        float _yVelocity;
        bool _shotReleased;
        bool _chargingShot;

        Event() = delete;
        explicit Event(unsigned int entityId);
    };

    Event::Event(unsigned int entityId) : _entityId(entityId),
                                          _xVelocity(0),
                                          _yVelocity(0),
                                          _shotReleased(false),
                                          _chargingShot(false)
    {
    }
}

#endif //RTYPE_EVENT_HPP