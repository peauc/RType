//
// Created by buis_p on 1/17/18.
//

#include "EnemyLoader/EnemyLoader.hpp"



EnemyLoader::EnemyLoader(const std::string &path, Engine::Game	&game) {
	stock.setPath(path);
	stock.loadByPath();
	for (const std::string &file : stock.getList()) {
		const std::string &str = path + file;
		enemies.insert(std::pair<const std::string, Engine::Entity *>(file, loader.getInstance(str, game)));
	}
}

 const std::map<const std::string, Engine::Entity*> &EnemyLoader::getEnemies() const {
	return (this->enemies);
}

void EnemyLoader::setup(const std::string &path, Engine::Game &game) {
	stock.setPath(path);
	stock.loadByPath();
	for (const std::string &file : stock.getList()) {
		const std::string &str = path + file;
		enemies.insert(std::pair<const std::string, Engine::Entity *>(file, loader.getInstance(str, game)));
	}
}
