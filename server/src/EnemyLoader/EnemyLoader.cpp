//
// Created by buis_p on 1/17/18.
//
//

#include <EnemyLoader/EnemyLoader.hpp>


EnemyLoader::EnemyLoader(const std::string &path) {
	stock.setPath(path);
	stock.loadByPath();
	for (const std::string &str : stock.getList())
		enemies.push_back(loader.getInstance(str));
}

 const std::vector<Engine::Entity*> &EnemyLoader::getEnemies() const {
	return (this->enemies);
}
