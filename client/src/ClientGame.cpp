/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#include "ClientGame.hpp"
#include "Graphic/RenderSFML.hpp"
#include "Graphic/MenuSFML.hpp"
#include "Graphic/SpriteSFML.hpp"
#include "Graphic/TextSFML.hpp"

ClientGame::ClientGame(const std::string &ip, const std::string &animationFile,
		       uint16_t width, uint16_t height)
	: _gameState(GAMESTATE::INMENU)
{
	this->_client.connect(ip); //TODO Async ? avec une queue de packets
	this->_render = std::make_unique<RenderSFML>(width, height, "R-TYPE");
	this->_resourcesLoader.loadAnimations(animationFile);
	this->_render->loadAnimations(this->_resourcesLoader.getAnimations());
	this->_startMenu = std::make_unique<MenuSFML>();
	this->createMenu();
}

void	ClientGame::run() noexcept
{
	std::queue<IRender::EventAction> eventsQueue;
	
	//
	std::unique_ptr<ISprite> sprite = std::make_unique<SpriteSFML>();
	this->_render->setAnimationToSprite(sprite.get(), 0, true);
	this->_objects.insert(std::make_pair((uint32_t)0, std::move(sprite)));
	// TODO delete
	
	this->_client.resetChrono();
	int nbTicks = 0; //TODO To change
	std::chrono::steady_clock::time_point begin
		= std::chrono::steady_clock::now();
	
	while (this->_render->isWindowOpen()) { //TODO Game Loop
		//TODO
		// Get Packets and Interpret
		if (std::chrono::duration_cast<std::chrono::milliseconds>
			    (std::chrono::steady_clock::now() - begin)
			    .count() > FRAMEDURATION) {
			eventsQueue = this->_render->pollEvents();
			this->_render->clear();
			this->drawSprites();
			this->_render->display();
			this->updateAnimations(nbTicks);
			this->processEvents(eventsQueue); // Send packets
			++nbTicks;
			begin = std::chrono::steady_clock::now();
		}
	}
}

/**
 * Check game state
 *  -INGAME --> Draw all sprites
 *  -INMENU --> Draw all sprites and texts of menu
 */
void ClientGame::drawSprites() noexcept
{
	if (this->_gameState == GAMESTATE::INGAME) {
		for (const auto &obj : this->_objects) {
			this->_render->draw(obj.second.get());
		}
	} else if (this->_gameState == GAMESTATE::INMENU) {
		for (const auto &sprite : _startMenu->getSpritesToDraw()) {
			this->_render->draw(sprite.get());
		}
		for (const auto &text : _startMenu->getTextsToDraw()) {
			this->_render->draw(text.get());
		}
	}
}

void ClientGame::updateAnimations(int &nbTicks) noexcept
{
	if (nbTicks == ANIMATIONDURATION) {
		for (const auto &obj : this->_objects) {
			obj.second->updateAnimation();
		}
		nbTicks = 0;
	}
}

void ClientGame::processEvents(std::queue<IRender::EventAction>
			       &eventsQueue) noexcept
{
	while (!eventsQueue.empty()) {
		const IRender::EventAction &event = eventsQueue.front();
		eventsQueue.pop();

		if (this->_gameState == GAMESTATE::INMENU &&
		    event == IRender::EventAction::MOUSE1) {
			this->processEventMenu(event);
		} else {
			//TODO Create Packet and send
		}
	}
}

void ClientGame::processEventMenu(const IRender::EventAction &event) noexcept
{
	for (const auto &sprite : _startMenu->getSpritesToDraw()) {
		if (this->_render->isSpriteClicked(
			sprite.get(), event)) {
			sprite->onClick();
		}
	}
}

void ClientGame::createMenu() noexcept
{
	auto background
		= this->_render->createSprite("../Assets/MenuSprite/space.jpg",
					      0, 0);
	auto playButton = this->_render->createSprite(
		"../Assets/MenuSprite/playActive.png", 0, 0);
	auto quitButton = this->_render->createSprite(
		"../Assets/MenuSprite/cancelActive.png", 0, 0);
	auto rtypeText(std::make_unique<TextSFML>(
		"../Assets/MenuSprite/ELRIOTT2.TTF", "R-TYPE", 80));
	
	playButton->setPos(-200, -300);
	playButton->setOnClick([&]() {
		this->_gameState = GAMESTATE::INGAME;
	});
	
	quitButton->setPos(-600, -300);
	quitButton->setOnClick([this]() {
		this->_render->closeWindow();
	});

	rtypeText->setPosX(300);
	
	this->_startMenu->addSprite(std::move(background));
	this->_startMenu->addSprite(std::move(playButton));
	this->_startMenu->addSprite(std::move(quitButton));
	this->_startMenu->addText(std::move(rtypeText));
}