//
// Created by buis_p on 1/17/18.
//
//

#include <EnemyLoader/EnemyLoader.hpp>


EnemyLoader::EnemyLoader() {
	stock.setPath("");
	stock.loadByPath();
	for (auto str : stock.getList())
		enemies.push_back(loader.getInstance(str));
}

EnemyLoader::EnemyLoader(const EnemyLoader &other) {}

EnemyLoader &EnemyLoader::operator=(const EnemyLoader &other) {
	return (*this);
}

 const std::vector<Engine::Entity*> &EnemyLoader::getEnemies() const {
	return (this->enemies);
}
