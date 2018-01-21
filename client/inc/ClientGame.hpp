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
	enum class	GAMESTATE
	{
		INMENU	= 0,
		INGAME
	};

	client::AsioClient 		_client;
	RessourcesLoader 		_resourcesLoader;
	std::unique_ptr<IRender>	_render;
	std::unique_ptr<IMenu>		_startMenu;
	std::unordered_map<uint32_t, std::unique_ptr<ISprite>>	_objects;
	GAMESTATE 			_gameState;
	
	const short FRAMEDURATION = 16;
	const short ANIMATIONDURATION = 16;

	void	drawSprites() noexcept;
	void	updateAnimations(int &nbTicks) noexcept;
	void	processEvents(std::queue<IRender::EventAction>
				  &eventsQueue) noexcept;
	void	processEventMenu(const IRender::EventAction &event) noexcept;
	void	createMenu() noexcept;
	
};

#endif // !RTYPE_CLIENTGAME_HPP_