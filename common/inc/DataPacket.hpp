/*
** EPITECH  PROJECT , 2020
** SFMLDemo
** File  description:
** 	No description
*/

#ifndef DATAPACKET_HPP
# define DATAPACKET_HPP

#include <cstddef>

namespace Packet
{
	enum	GameState
	{
		INGAME = 0,
		WON = 1,
		LOST = 2
	};
	
	enum	EntityState
	{
		ALIVE = 0,
		DEAD = 1,
		NOT_DISPLAYED = 2
	};
	
	struct	PlayerScore
	{
		char playerId;
		unsigned int score;
	};
	
	struct	Lobby
	{
		bool gameStarted;
		unsigned char numberOfPlayers;
	};
	
	struct	Score
	{
		GameState gameState;
		struct PlayerScore playerScore[4];
	};
	
	struct	Object
	{
		short x;
		short y;
		EntityState entityState;
		bool animated;
		bool hit;
		unsigned int id;
		unsigned char objectId;
		unsigned char animationId;
	};
	
	struct	Sound
	{
		unsigned char soundId;
		bool music;
		bool repeat;
	};
	
	struct	Input
	{
		short xVelocity;
		short yVelocity;
		bool shot;
		bool charged;
	};
	
	struct	Connection
	{
		unsigned short seed;
	};
	
	union	UData
	{
		Connection connection;
		Input input;
		Lobby lobby;
		Score score;
		Object object;
		Sound sound;
	};
	
	struct	DataPacket
	{
		DataPacket() = default;
		explicit DataPacket(unsigned short cmd) : cmd(cmd) {}
		DataPacket(const DataPacket &pket)
			: cmd(pket.cmd), data(pket.data) {}

		unsigned short cmd{0};
		union UData data{};
	};

	const size_t PACKETSIZE = sizeof(DataPacket);

	enum	Commands
	{
		CONNECT	= 0,
		DISCONNECT,
		CONNECTED,
		DISCONNECTED,
		STARTGAME,
		READY,
		POSITION,
		EVENT,
		PONG,
		UNKNOWN
	};
}

#endif //SFMLDEMO_DATAPACKET_HPP
