//
// Created by buis_p on 1/18/18.
//

#ifndef RTYPE_BERZERKER_HPP
#	define RTYPE_BERZERKER_HPP

#	include "Entity.hpp"
#	include "EnemyMoveComponent.hpp"
#	include "EnemyAIComponent.hpp"
#	include "EnemyPhysicsComponent.hpp"
#	include "EnemyGraphicsComponent.hpp"
#	include "Components/HealthComponent.hpp"

class Berzerker : public Engine::Entity {
public:
	Berzerker(Engine::Game &game);
	Berzerker(const Berzerker &other) = default;
	Berzerker	&operator=(const Berzerker &other) = default;
	~Berzerker() = default;
};

#endif //RTYPE_BERZERKER_HPP
