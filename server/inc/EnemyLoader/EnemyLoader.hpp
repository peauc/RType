//
// Created by buis_p on 1/17/18.
//

#ifndef RTYPE_ENEMYLOADER_HPP
#	define RTYPE_ENEMYLOADER_HPP

#	include <iostream>
#   include <map>
#	include "Entity.hpp"
#	include "LStock.hpp"
#	include "DLLoader.hpp"

class EnemyLoader {
private:
	LStock		stock;
	DLLoader<Engine::Entity>	loader;
	std::map<const std::string, Engine::Entity*>	enemies;
public:
	EnemyLoader() = default;
	~EnemyLoader() = default;

	std::unique_ptr<std::map<const std::string, Engine::Entity*>> getEnemies() const;
	void setup(const std::string &path, Engine::Game &game);
};

#endif //RTYPE_ENEMYLOADER_HPP
