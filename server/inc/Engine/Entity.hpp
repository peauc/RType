//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_ENTITY_HPP
#define RTYPE_ENTITY_HPP

#include <vector>
#include <memory>
#include "AComponent.hpp"
#include "TransformComponent.hpp"

namespace Engine {
	class Entity
	{
	public:
		Entity(unsigned int id);
		~Entity() = default;

		void update();
		void addComponent(AComponent *component);
		const Mediator &getMediator() const;
		const TransformComponent &getTransformComponent() const;
		const unsigned int getId() const;

		bool operator==(unsigned int id);
		bool operator==(const Entity &other);

	private:
		unsigned int _id;
		TransformComponent _transformComponent;
		std::vector<std::unique_ptr<AComponent>> _components;
		Mediator _mediator;
	};
}

#endif //RTYPE_ENTITY_HPP
