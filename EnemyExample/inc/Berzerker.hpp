//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_BERZERKER_HPP
#	define RTYPE_BERZERKER_HPP

#	include <Engine/Entity.hpp>

class Berzerker : Engine::Entity {
public:
	Berzerker();
	Berzerker(const Berzerker &other);
	Berzerker	&operator=(const Berzerker &other) = default;
	~Berzerker() = default;
};

#endif //RTYPE_BERZERKER_HPP
