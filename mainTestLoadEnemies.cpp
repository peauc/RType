//
// Created by buis_p on 1/18/18.
//


// Copier ce main dans le dossier /server/src, pour test, remplacer le main du serveur par ce dernier.

#include <Engine/Game.hpp>
#include <EnemyLoader/EnemyLoader.hpp>

int	main() {
	Engine::Game	game;
	EnemyLoader						loader("../DLEnemies/", game);
	std::vector<Engine::Entity*>	enemies = loader.getEnemies();

	// TODO Create enemies to test
	std::cout << "Il y a " << enemies.size() << " enemies!" << std::endl;

	if (enemies.size() > 0)
		enemies[0]->update();
}
