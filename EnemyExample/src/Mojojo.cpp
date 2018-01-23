//
// Created by buis_p on 1/18/18.
//

/*
 *
 *		Example: Creation of Mojojo enemy
 *
 */

#include <iostream>
#include "Mojojo.hpp"
#include "MojojoMove.hpp"
#include "MojojoAI.hpp"
#include "MojojoGraphics.hpp"
#include "MojojoPhysics.hpp"
#include "MojojoWeapon.hpp"
#include "HealthComponent.hpp"

/*
 *
 * 	In constructor, you have to declare all the components and add them to your main object "Mojojo"
 *
 */

Mojojo::Mojojo(Engine::Game &game) {
	Engine::AComponent	*AIComponent = new Component::MojojoAI(this);
	Engine::AComponent	*moveComponent = new Component::MojojoMove(this);
	Component::AGraphicsComponent	*graphicComponent = new Component::MojojoGraphics(this, game.getResourceLoader().get());
	Engine::AComponent	*physicsComponent = new Component::MojojoPhysics(this, Engine::Hitbox(
			Engine::Hitbox::Type::ENEMY, graphicComponent->getRelativeStartPos(),
			graphicComponent->getRange()));
	Engine::AComponent *mojojoWeaponComponent = new Component::MojojoWeapon(this, &game);
	Engine::AComponent	*healthComponent = new Component::HealthComponent(this, game.getWorld().get(), 50, false, false);

	if (game.getWorld()->getMediator() != nullptr) {
		physicsComponent->registerToMediator(game.getWorld()->getMediator().get());
	}
	if (game.getWorld()->getCamera() != nullptr) {
		graphicComponent->addObserver(game.getWorld()->getCamera().get());
	}

	this->addComponent(AIComponent);
	this->addComponent(moveComponent);
	this->addComponent(mojojoWeaponComponent);
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
	Engine::Entity *entryPoint(Engine::Game	&game) {
		return (new Mojojo(game));
	}
}
