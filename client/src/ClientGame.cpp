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
#include "Graphic/BackgroundSFML.hpp"

ClientGame::ClientGame(const std::string &ip,
		       const std::string &port,
		       unsigned short seed,
		       const std::string &animationFile,
		       uint16_t width, uint16_t height)
	: _gameState(GameState::INMENU), _waitingReady(false)
{
	this->_client.connect(ip, port, seed);
	this->_render = std::make_unique<RenderSFML>(width, height, "R-TYPE");
	if (!this->_render) {
		throw std::runtime_error("Can't open window");
	}
	this->_resourcesLoader.loadAnimations(animationFile);
	this->_render->loadAnimations(this->_resourcesLoader.getAnimations());
	this->_startMenu = std::make_unique<MenuSFML>();
	try {
		this->createMenu();
	} catch (const std::runtime_error &e) {
		e.what();
		throw std::runtime_error("Can't load start menu");
	}
	this->setBackgrounds();
}

/**
 * Run the game
 *
 * Get packets and interpret them
 * Get user events
 * Display sprites and update animations
 * Process user events
 */
void	ClientGame::run() noexcept
{
	std::queue<IRender::EventAction>	eventsQueue;
	std::vector<Packet::DataPacket>		packetList;
	std::chrono::steady_clock::time_point	begin
		= std::chrono::steady_clock::now();
	int					nbTicks = 0;

	this->_client.resetChrono();
	while (this->_render->isWindowOpen()) {
		this->_client.tick();
		this->interpretPacket(this->_client.getDataPacketList());
		if (std::chrono::duration_cast<std::chrono::milliseconds>
			    (std::chrono::steady_clock::now() - begin)
			    .count() > FRAMEDURATION) {
			eventsQueue = this->_render->pollEvents();
			this->drawOperations(nbTicks);
			this->deleteDeadSprites();
			this->processEvents(eventsQueue);
			if (this->_waitingReady) {
				this->sendReadyPacket();
			}
			begin = std::chrono::steady_clock::now();
		}
	}
}

/**
 * Operations in order to draw on screen
 * @param nbTicks
 */
void	ClientGame::drawOperations(int &nbTicks)
{
	this->_render->clear();
	this->drawSprites();
	this->_render->display();
	this->updateAnimations(nbTicks);
	++nbTicks;
}

/**
 * Check game state
 *  -INGAME --> Draw all sprites and backgrounds
 *  -INMENU --> Draw all sprites and texts of menu
 */
void ClientGame::drawSprites() noexcept
{
	if (this->_gameState == GameState::INGAME) {
		for (const auto &bg : this->_backgrounds) {
			if (bg) {
				this->_render->draw(bg.get());
			}
		}
		for (const auto &obj : this->_objects) {
			if (obj.second) {
				this->_render->draw(obj.second.get());
			}
		}
	} else if (this->_gameState == GameState::INMENU) {
		for (const auto &sprite : _startMenu->getSpritesToDraw()) {
			if (sprite) {
				this->_render->draw(sprite.get());
			}
		}
		for (const auto &text : _startMenu->getTextsToDraw()) {
			if (text) {
				this->_render->draw(text.get());
			}
		}
	}
}

/**
 * Call updateAnimation on each sprites
 * and set their new texture to be drawn next frame
 * @param nbTicks number of frames played since last updateAnimation
 */
void ClientGame::updateAnimations(int &nbTicks) noexcept
{
	if (nbTicks == ANIMATIONDURATION) {
		for (const auto &obj : this->_objects) {
			obj.second->updateAnimation();
		}
		nbTicks = 0;
	}
	for (const auto &bg : this->_backgrounds) {
		if (bg) {
			bg->updateAnimation();
		}
	}
}

/**
 * Process each events in the queue
 * If in menu, call processEventMenu
 * If in game, modify Input struct and send an event DataPacket afterwards
 * If event is quit send quit to server
 * @param eventsQueue
 */
void ClientGame::processEvents(std::queue<IRender::EventAction>
			       &eventsQueue) noexcept
{
	Packet::Input	input{0, 0, false, false};

	while (!eventsQueue.empty()) {
		const IRender::EventAction &event = eventsQueue.front();
		eventsQueue.pop();

		if (event == IRender::EventAction::QUIT) {
			this->_client.sendMessage(Packet::DataPacket(
				(int)Packet::Commands::DISCONNECT));
		}
		if (this->_gameState == GameState::INMENU &&
		    event == IRender::EventAction::MOUSE1) {
			this->processEventMenu(event);
		} else if (this->_gameState == GameState::INGAME) {
			this->modifyInputPacket(event, input);
		}
	}
	if (this->_gameState == GameState::INGAME) {
		this->sendEventPacket(input);
	}
	this->sendPong();
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

/**
 * Add sprites and texts to start menu
 */
void ClientGame::createMenu()
{
	auto background = this->_render
			      ->createSprite("../Assets/Menu/background.jpg");
	auto playButton = this->_render->createSprite(
		"../Assets/Menu/play.png");
	auto quitButton = this->_render->createSprite(
		"../Assets/Menu/quit.png");
	auto rtypeText(std::make_unique<TextSFML>(
		"../Assets/Menu/spaceAge.ttf", "R-TYPE", 80));
	
	playButton->setPos(-(this->_render->getWidth() / 3),
			   -(this->_render->getHeight() / 2));
	playButton->setOnClick([&]() {
		this->sendReadyPacket();
	});
	
	quitButton->setPos(-(this->_render->getWidth() / 3 * 2),
			   -(this->_render->getHeight() / 2));
	quitButton->setOnClick([this]() {
		this->_render->closeWindow();
	});
	
	rtypeText->setPosX(this->_render->getWidth() / 3);
	
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
	short	speed = 10'000;

	switch (event) {
		case IRender::EventAction::UP:
			input.yVelocity = -speed;
			break;
		case IRender::EventAction::DOWN:
			input.yVelocity = speed;
			break;
		case IRender::EventAction::LEFT:
			input.xVelocity = -speed;
			break;
		case IRender::EventAction::RIGHT:
			input.xVelocity = speed;
			break;
		case IRender::EventAction::SPACE:
			input.shot = true;
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

/**
 * Create and send a DataPacket with the command Ready
 */
void ClientGame::sendReadyPacket() noexcept
{
	this->_client.sendMessage(Packet::DataPacket(
		(int)Packet::Commands::READY));
}

void ClientGame::sendPong() noexcept
{
	static int frames = 0;
	
	frames = frames++ % 256;
	if (frames == 0) {
		this->_client.sendMessage(Packet::DataPacket(
			(int)Packet::Commands::PONG));
	}
}

/**
 * Interpret all packets in the vector
 * @param packets vector of packets
 */
void ClientGame::interpretPacket(const std::vector<Packet::DataPacket>
				 &packets) noexcept
{
	for (const auto &packet : packets) {
		switch (packet.cmd) {
			case Packet::Commands::STARTGAME:
				this->_waitingReady = false;
				this->_gameState = GameState::INGAME;
				break;
			case Packet::Commands::POSITION:
				this->updateObject(packet.data.object);
				break;
			case Packet::Commands::READY:
				this->_waitingReady = false;
				break;
			default:
				break;
		}
	}
}

/**
 * Update object (or add if it doesn't exist yet) in the object vector
 * @param packet with object info
 */
void ClientGame::updateObject(const Packet::Object &object) noexcept
{
	auto it = this->_objects.find(object.id);
	if (it != this->_objects.end()) {
		this->updateInfosObject(it->second.get(), object.animated,
					object);
	} else {
		std::unique_ptr<ISprite> sprite
			= std::make_unique<SpriteSFML>();
		this->updateInfosObject(sprite.get(), object.animated, object);
		this->_objects.insert(std::make_pair(object.id,
						     std::move(sprite)));
	}
}

/**
 * Update object with infos of packet
 * @param sprite Object to be updated
 * @param repeatAnimation Animation to be repeated or not
 * @param objInfos infos
 */
void ClientGame::updateInfosObject(ISprite *sprite, bool repeatAnimation,
				   const Packet::Object &objInfos) noexcept
{
	std::pair<short, short> pos = this->calculateRealPosition(objInfos.x,
								  objInfos.y);
	sprite->setPos(pos.first, pos.second);
	repeatAnimation = !(objInfos.entityState == Packet::EntityState::DEAD);
	if (sprite->getAnimationId() != objInfos.animationId) {
		this->_render->setAnimationToSprite(sprite,
						    objInfos.animationId,
						    repeatAnimation);
	} else if (sprite->isAnimationRepeating() != repeatAnimation) {
		sprite->setRepeatAnimation(repeatAnimation);
	}
	sprite->setDisplay(objInfos.entityState !=
				   Packet::EntityState::NOTDISPLAYED);
}

/**
 * Get real position on window from the position in Position Packet which
 * varies between 0 and 10'000
 * @param x
 * @param y
 * @return pos
 */
std::pair<short, short> ClientGame::calculateRealPosition(short x,
							  short y) noexcept
{
	int screensize = 10'000;

	x = (short)((x < 0) ? 0 : x);
	y = (short)((y < 0) ? 0 : y);
	x = (short)((x > screensize) ? screensize : x);
	y = (short)((y > screensize) ? screensize : y);
	auto realX = -(short)(x * this->_render->getWidth() / screensize);
	auto realY = -(short)(y * this->_render->getHeight() / screensize);
	return (std::make_pair(realX, realY));
}

/**
 * Delete all objects from _objects vector
 * which have their bool waitingToBeDeleted set to true
 */
void ClientGame::deleteDeadSprites()
{
	for (auto it = this->_objects.begin(); it != this->_objects.end();) {
		if (it->second->isWaitingToBeDeleted()) {
			this->_objects.erase(it++);
		} else {
			++it;
		}
	}
}

/**
 * Setting multiple backgrounds in order to create a parallax effect
 */
void ClientGame::setBackgrounds() noexcept
{
	try {
		this->_backgrounds.emplace_back(
			std::make_unique<BackgroundSFML>(
				"../Assets/backbackground.png", 1280, 720));
		this->_backgrounds.emplace_back(
			std::make_unique<BackgroundSFML>(
				"../Assets/background.png", 1704, 960,
				2, 1));
		this->_backgrounds.emplace_back(
			std::make_unique<BackgroundSFML>(
				"../Assets/background.png",
				1704, 960, 1, 0.2));
	} catch(const std::runtime_error &e) {
		e.what();
	}
}
