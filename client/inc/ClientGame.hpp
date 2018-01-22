/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_CLIENTGAME_HPP_
# define RTYPE_CLIENTGAME_HPP_

# include <unordered_map>
# include <memory>
# include "Graphic/ISprite.hpp"
# include "Graphic/IRender.hpp"
# include "Graphic/IMenu.hpp"
# include "AsioClient.hpp"
# include "RessourcesLoader.hpp"

class ClientGame
{
public:
	ClientGame(const std::string &ip,
		   const std::string &animationFile,
		   uint16_t width = 800, uint16_t height = 600);
	ClientGame(const ClientGame &) = delete;
	ClientGame &operator=(const ClientGame &) = delete;
	~ClientGame() = default;

	void	run() noexcept;

private:
	enum class	GameState
	{
		INMENU	= 0,
		INGAME
	};

	client::AsioClient 		_client;
	RessourcesLoader 		_resourcesLoader;
	std::unique_ptr<IRender>	_render;
	std::unique_ptr<IMenu>		_startMenu;
	std::unordered_map<uint32_t, std::unique_ptr<ISprite>>	_objects;
	GameState 			_gameState;
	bool 				_waitingReady;
	
	const short FRAMEDURATION = 16;
	const short ANIMATIONDURATION = 16;

	void	drawSprites() noexcept;
	void	updateAnimations(int &nbTicks) noexcept;
	void	processEvents(std::queue<IRender::EventAction>
				  &eventsQueue) noexcept;
	void 	drawOperations(int &nbTicks);
	void	processEventMenu(const IRender::EventAction &event) noexcept;
	void	createMenu();
	void	modifyInputPacket(const IRender::EventAction &event,
				      Packet::Input &input) noexcept;
	void	sendEventPacket(const Packet::Input &input) noexcept;
	void	sendReadyPacket() noexcept;
	void	setVelocityInput(short x, short y,
				     Packet::Input &input) noexcept;
	void	interpretPacket(const std::vector<Packet::DataPacket>
				     &packets) noexcept;
	void	updateObject(const Packet::DataPacket &packet) noexcept;
	void	updateInfosObject(ISprite *sprite, bool repeatAnimation,
				      const Packet::Object &objInfos) noexcept;
	std::pair<short, short>	calculateRealPosition(short x,
							     short y) noexcept;
};

#endif // !RTYPE_CLIENTGAME_HPP_