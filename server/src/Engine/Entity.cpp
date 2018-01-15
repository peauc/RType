//
// Created by romain on 12/01/18.
//

#include <Engine/Entity.hpp>

Engine::Entity::Entity() : _transformComponent(this), _components(), _mediator()
{
}

void Engine::Entity::update()
{
    for (int i = 0; i < _components.size(); ++i) {
        this->_components[i]->update();
    }
}

void Engine::Entity::addComponent(Engine::AComponent *component)
{
    this->_components.push_back(std::unique_ptr<AComponent>(component));
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


