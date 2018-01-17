/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifdef __unix__
#include <cstdlib>
#endif

#include <memory>
#include <chrono>
#include <iostream>
#include "SpriteSFML.hpp"
#include "Message.hpp"
#include "Texture.hpp"
#include "RenderSFML.hpp"

#include "RessourcesLoader.hpp"

void    gameLoop() //TODO A mettre dans une classe
{
	std::unique_ptr<IRender> render = std::make_unique<RenderSFML>();
	std::unique_ptr<ISprite> sp;
	uint32_t tileNumber = 0;
	
	render->openWindow(800, 600, "R-Type");
	
	try {
		sp = render->createSprite("../Assets/commie.png",
					  33,
					  36);
		sp->selectSprite(tileNumber, 0);
	} catch(const std::exception &e) {
		e.what();
		render->closeWindow();
		return;
	}
	
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	
	while (render->isWindowOpen())
	{
		render->pollEvents();
		render->clear();
		render->draw(sp.get());
		render->display();
		
		if (std::chrono::duration_cast<std::chrono::microseconds>
			    (std::chrono::steady_clock::now() - begin).count() >
		    250000) {
			sp->selectSprite((++tileNumber) % 8, 0);
			begin = std::chrono::steady_clock::now();
		}
		
	}
}

void    gameLoop2() //TODO A mettre dans une classe
{
	std::unique_ptr<IRender> render = std::make_unique<RenderSFML>();
	std::unique_ptr<ISprite> sp = std::make_unique<SpriteSFML>();
	RessourcesLoader rl; //TODO A changer le nom en resourcesLoader
	
	rl.loadAnimations("../AssetsId.txt");
	
/*
	std::vector<Texture> vecTex;
	Texture t1;
	t1.filePath = "../Assets/commie.png";
	t1.left = 0 * 33;
	t1.top = 0;
	t1.height = 36;
	t1.width = 33;

	Texture t2;
	t2.filePath = "../Assets/commie.png";
	t2.left = 1 * 33;
	t2.top = 0;
	t2.height = 36;
	t2.width = 33;

	Texture t3;
	t3.filePath = "../Assets/commie.png";
	t3.left = 2 * 33;
	t3.top = 0;
	t3.height = 36;
	t3.width = 33;

	vecTex.push_back(t1);
	vecTex.push_back(t2);
	vecTex.push_back(t3);
	std::unordered_map<uint32_t, std::vector<Texture>> textMap;
	textMap.insert(std::make_pair((uint32_t)0, vecTex));
*/
	
	render->openWindow(800, 600, "R-Type");
	render->loadAnimations(rl.getAnimations());
	render->setAnimationToSprite(sp.get(), 0, true);
	sp->setPosX(0);
	sp->setPosY(0);
	
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	
	while (render->isWindowOpen())
	{
		render->pollEvents();
		render->clear();
		render->draw(sp.get());
		render->display();
		
		if (std::chrono::duration_cast<std::chrono::microseconds>
			    (std::chrono::steady_clock::now() - begin).count() >
		    250000) {
			sp->updateAnimation();
			begin = std::chrono::steady_clock::now();
		}
		
	}
}

int     main(int argc, char **argv, char **env)
{
#ifdef __unix__
	if (env == nullptr || getenv("DISPLAY") == nullptr)
		return (1);
#endif
//	gameLoop();
	gameLoop2();
	//TODO catch bad_alloc
}