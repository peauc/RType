//
// Created by buis_p on 1/17/18.
//

#include "EnemyLoader/EnemyLoader.hpp"



EnemyLoader::EnemyLoader(const std::string &path, Engine::Game	&game) {
	stock.setPath(path);
	stock.loadByPath();
	if (stock.isFolder) {
		for (const std::string &file : stock.getList()) {
			const std::string &str = path + file;
			enemies.insert(std::pair<const std::string, Engine::Entity *>(file, loader.getInstance(str, game)));
		}
	}
}

std::unique_ptr<std::map<const std::string, Engine::Entity*>> EnemyLoader::getEnemies() const {
	if (!stock.isFolder) {
		std::unique_ptr<std::map<const std::string, Engine::Entity *>> ptr = std::make_unique<
				std::map<const std::string, Engine::Entity *>>(this->enemies);
		return (std::move(ptr));
	}
	return (nullptr);
}

void EnemyLoader::setup(const std::string &path, Engine::Game &game) {
	stock.setPath(path);
	stock.loadByPath();
	if (stock.isFolder) {
		for (const std::string &file : stock.getList()) {
			const std::string &str = path + file;
			enemies.insert(std::pair<const std::string, Engine::Entity *>(file, loader.getInstance(str, game)));
		}
	}
}
