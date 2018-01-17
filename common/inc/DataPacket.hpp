/*
** EPITECH  PROJECT , 2020
** SFMLDemo
** File  description:
** 	No description
*/

#ifndef DATAPACKET_HPP
# define DATAPACKET_HPP

namespace Packet {
enum GameState {
	INGAME = 0,
	WON = 1,
	LOST = 2
};
enum EntityState {
	ALIVE = 0,
	DEAD = 1,
};
struct PlayerScore {
	char playerId;
	unsigned int score;
};
struct Lobby {
	bool gameStarted;
	unsigned char numberOfPlayers;
};
struct Score {
	GameState gameState;
	struct PlayerScore playerScore[4];
};
struct Object {
	float x;
	float y;
	EntityState entityState;
	bool animated;
	bool hit;
	unsigned int id;
	unsigned char objectId;
	unsigned char animationId;
};
struct Input {
	float Xvelocity;
	float Yvelocity;
	bool shot;
	bool charged;
};
struct Connection {
	unsigned short seed;
};
union UData {
	Connection connection;
	Input input;
	Lobby lobby;
	Score score;
	Object object;
};
struct DataPacket {
	unsigned short cmd;
	union UData data;
};
const size_t PACKETSIZE = sizeof(DataPacket);
}
#endif //SFMLDEMO_DATAPACKET_HPP
