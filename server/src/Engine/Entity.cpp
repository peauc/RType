//
// Created by romain on 12/01/18.
//

#include <Engine/Entity.hpp>

Engine::Entity::Entity(unsigned int hp, float speed) : _hp(hp), _speed(speed), _coordinates(), _components(), _mediator()
{
}

void Engine::Entity::update()
{
    for (std::unique_ptr<AComponent> component : this->_components) {
        component->update();
    }
}

void Engine::Entity::addComponent(Engine::AComponent *component)
{
    this->_components.push_back(component);
    component->registerToMediator(this->_mediator);
}

const Engine::Mediator &Engine::Entity::getMediator() const
{
    return _mediator;
}

const Engine::TransformComponent &Engine::Entity::getTransformComponent() const
{
    return _transformComponent;
}

const unsigned int Engine::Entity::getId() const
{
    return _id;
}


