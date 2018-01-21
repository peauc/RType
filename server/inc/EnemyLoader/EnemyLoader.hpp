//
// Created by buis_p on 1/17/18.
//

#ifndef RTYPE_ENEMYLOADER_HPP
#	define RTYPE_ENEMYLOADER_HPP

#	include <iostream>
#	include <vector>
#	include <Engine/Entity.hpp>
#	include <EnemyLoader/LStock.hpp>
#	include <EnemyLoader/DLLoader.hpp>

class EnemyLoader
{
private:
	LStock stock;
	DLLoader<Engine::Entity> loader;
	std::vector<Engine::Entity *> enemies;
public:
	explicit EnemyLoader(const std::string &path);
	EnemyLoader(const EnemyLoader &other) = default;
	EnemyLoader &operator=(const EnemyLoader &other) = default;
	~EnemyLoader() = default;

	const std::vector<Engine::Entity *> &getEnemies() const;
};

#endif //RTYPE_ENEMYLOADER_HPP
