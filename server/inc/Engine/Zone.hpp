//
// Created by romain on 21/01/18.
//

#ifndef RTYPE_ZONE_HPP
#define RTYPE_ZONE_HPP

#include <string>
#include <vector>
#include <Common/Vector2d.hpp>
#include "Entity.hpp"
#include "Game.hpp"

namespace Engine {
	namespace MapLoader {
		class Zone
		{
		public:
			Engine::Entity *createZone(Game &game) const;
		private:
			struct ZoneObject
			{
				const std::string _libname;
				Vector2d _pos;

				Engine::Entity *createEntity(Game &game) const;
			};

			Vector2d topLeftCoords;
			Vector2d bottomRightCoords;
			std::vector<ZoneObject> _zoneObjects;
		};
	}
}

#endif //RTYPE_ZONE_HPP
