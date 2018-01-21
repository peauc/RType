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
	: _gameState(GameState::INGAME)
{
//	this->_client.connect(ip); //TODO Async ? avec une queue de packets
	this->_render = std::make_unique<RenderSFML>(width, height, "R-TYPE");
	this->_resourcesLoader.loadAnimations(animationFile);
	this->_render->loadAnimations(this->_resourcesLoader.getAnimations());
//	this->_startMenu = std::make_unique<MenuSFML>();
//	try {
//		this->createMenu();
//	} catch (const std::runtime_error &e) {
//		e.what();
//		throw std::runtime_error("Can't load start menu");
//	}
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
	if (this->_gameState == GameState::INGAME) {
		for (const auto &obj : this->_objects) {
			this->_render->draw(obj.second.get());
		}
	} else if (this->_gameState == GameState::INMENU) {
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

/**
 *
 * @param eventsQueue
 */
void ClientGame::processEvents(std::queue<IRender::EventAction>
			       &eventsQueue) noexcept
{
	Packet::Input	input{0, 0, false, false};

	while (!eventsQueue.empty()) {
		const IRender::EventAction &event = eventsQueue.front();
		eventsQueue.pop();

		if (this->_gameState == GameState::INMENU &&
		    event == IRender::EventAction::MOUSE1) {
			this->processEventMenu(event);
		} else if (this->_gameState == GameState::INGAME) {
			this->modifyInputPacket(event, input);
		}
	}
	this->sendEventPacket(input);
}

/**
 * Check if a sprite from the menu has been clicked.
 * If yes, execute the onClick function attached to the sprite
 * @param event Event to be passed to isSpriteClicked
 */
void ClientGame::processEventMenu(const IRender::EventAction &event) noexcept
{
	for (const auto &sprite : _startMenu->getSpritesToDraw()) {
		if (this->_render->isSpriteClicked(
			sprite.get(), event)) {
			sprite->onClick();
		}
	}
}

void ClientGame::createMenu()
{
	auto background
		= this->_render->createSprite("../Assets/MenuSprite/spac.jpg",
					      0, 0);
	auto playButton = this->_render->createSprite(
		"../Assets/MenuSprite/playActive.png", 0, 0);
	auto quitButton = this->_render->createSprite(
		"../Assets/MenuSprite/cancelActive.png", 0, 0);
	auto rtypeText(std::make_unique<TextSFML>(
		"../Assets/MenuSprite/ELRIOTT2.TTF", "R-TYPE", 80));
	
	playButton->setPos(-200, -300);
	playButton->setOnClick([&]() {
		this->_gameState = GameState::INGAME;
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

/**
 * Modify Input Packet
 * @param event Depending on the event, the input is modified
 * @param input Input to be modified
 */
void	ClientGame::modifyInputPacket(const IRender::EventAction &event,
					  Packet::Input &input) noexcept
{
	short	speed = 10000;

	switch (event) {
		case IRender::EventAction::UP:
			this->setVelocityInput(0, -speed, input);
			break;
		case IRender::EventAction::DOWN:
			this->setVelocityInput(0, speed, input);
			break;
		case IRender::EventAction::LEFT:
			this->setVelocityInput(-speed, 0, input);
			break;
		case IRender::EventAction::RIGHT:
			this->setVelocityInput(speed, 0, input);
			break;
		case IRender::EventAction::SPACE:
			input.charged = true;
			break;
		case IRender::EventAction::MOUSE1:
			input.charged = true;
			break;
		default:
			break;
	}
}

/**
 * Create and send a DataPacket with the command Event and with an input
 * @param input
 */
void ClientGame::sendEventPacket(const Packet::Input &input) noexcept
{
	Packet::DataPacket packet((int)Packet::Commands::EVENT);
	packet.data.input = input;
	this->_client.sendMessage(packet);
}

void	ClientGame::setVelocityInput(short x, short y,
					 Packet::Input &input) noexcept
{
	input.yVelocity = x;
	input.xVelocity = y;
}
