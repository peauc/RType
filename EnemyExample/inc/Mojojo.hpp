//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_MOJOJO_HPP
#	define RTYPE_MOJOJO_HPP

#include "Entity.hpp"

namespace Engine {
	class Game;
}

class Mojojo : public Engine::Entity {
public:
	Mojojo(Engine::Game &game);
	Mojojo(const Mojojo &other) = default;
	Mojojo	&operator=(const Mojojo &other) = default;
	~Mojojo() = default;
};

#endif //RTYPE_Mojojo_HPP
