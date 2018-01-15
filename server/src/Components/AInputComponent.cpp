//
// Created by romain on 15/01/18.
//

#include <Components/AInputComponent.hpp>

Component::AInputComponent::AInputComponent(Engine::Entity &parentEntity) : AComponent(parentEntity)
{

}

const Engine::Event &Component::AInputComponent::getEvent() const
{
    return *this->event;
}
