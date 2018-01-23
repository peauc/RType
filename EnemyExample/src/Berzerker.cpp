//
// Created by buis_p on 1/18/18.
//

/*
 *
 *		Example: Creation of Berzerker enemy
 *
 */

#include <iostream>
#include "Berzerker.hpp"
#include "EnemyMoveComponent.hpp"
#include "EnemyAIComponent.hpp"
#include "EnemyGraphicsComponent.hpp"
#include "EnemyPhysicsComponent.hpp"
#include "HealthComponent.hpp"

/*
 *
 * 	In constructor, you have to declare all the components and add them to your main object "Berzerker"
 *
 */

Berzerker::Berzerker(Engine::Game &game)
{
	Engine::AComponent *AIComponent = new Component::EnemyAIComponent(this);
	Engine::AComponent *enemyMoveComponent = new Component::EnemyMoveComponent(this, 500);
	Component::AGraphicsComponent *graphicComponent = new Component::EnemyGraphicsComponent(this,
																							game.getResourceLoader().get());
	Engine::AComponent *physicsComponent = new Component::EnemyPhysicsComponent(this, Engine::Hitbox(
			Engine::Hitbox::Type::ENEMY, graphicComponent->getRelativeStartPos(),
			graphicComponent->getRange()));
	Engine::AComponent *healthComponent = new Component::HealthComponent(this, game.getWorld().get(), 50, false, false);

	if (game.getWorld()->getMediator() != nullptr) {
		physicsComponent->registerToMediator(game.getWorld()->getMediator().get());
	}

	if (game.getWorld()->getCamera() != nullptr) {
		graphicComponent->addObserver(game.getWorld()->getCamera().get());
	}

	this->addComponent(AIComponent);
	this->addComponent(enemyMoveComponent);
	this->addComponent(graphicComponent);
	this->addComponent(physicsComponent);
	this->addComponent(healthComponent);
}

/*
 *
 * 	Entrypoint will be charged by the DDLoader (Dynamyc Library Loader)
 *
 * 	Just return new instanciation of your main object
 */

extern "C" {
Engine::Entity *entryPoint(Engine::Game &game)
{
	return (new Berzerker(game));
}
}
