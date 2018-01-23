//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_EVENT_HPP
#define RTYPE_EVENT_HPP

namespace Engine {
	struct Event
	{
		unsigned int _entityId;
		short _xVelocity;
		short _yVelocity;
		bool _shotReleased;
		bool _chargingShot;

		Event() = delete;
		explicit Event(unsigned int entityId);
		Event(unsigned int, short, short, bool, bool);
	};
}

#endif //RTYPE_EVENT_HPP