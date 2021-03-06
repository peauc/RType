//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_BERZERKER_HPP
#	define RTYPE_BERZERKER_HPP

#include "Entity.hpp"

namespace Engine {
	class Game;
}

class Berzerker : public Engine::Entity {
public:
	Berzerker(Engine::Game &game);
	Berzerker(const Berzerker &other) = default;
	Berzerker	&operator=(const Berzerker &other) = default;
	~Berzerker() = default;
};

#endif //RTYPE_BERZERKER_HPP
