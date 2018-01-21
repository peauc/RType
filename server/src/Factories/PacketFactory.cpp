//
// Created by romain on 18/01/18.
//

#include "PacketFactory.hpp"

Packet::DataPacket *PacketFactory::createObjectPacket(short x, short y, Packet::EntityState entityState, bool hit,
													  unsigned int id,
													  unsigned char animationId) noexcept
{
	Packet::DataPacket *dataPacket = new Packet::DataPacket;

	dataPacket->cmd = Packet::Commands::POSITION;
	dataPacket->data.object.entityState = entityState;
	dataPacket->data.object.x = x;
	dataPacket->data.object.y = y;
	dataPacket->data.object.animated = true;
	dataPacket->data.object.hit = hit;
	dataPacket->data.object.id = id;
	dataPacket->data.object.animationId = animationId;

	return dataPacket;
}

Packet::DataPacket *PacketFactory::createScorePacket(Packet::GameState gameState,
													 const std::vector<Packet::PlayerScore> &playerScores) noexcept
{
	Packet::DataPacket *dataPacket = new Packet::DataPacket;

	dataPacket->cmd = 0;
	dataPacket->data.score.gameState = gameState;

	for (unsigned int i = 0; i < playerScores.size(); ++i) {
		dataPacket->data.score.playerScore[i] = playerScores[i];
	}

	return dataPacket;
}

Packet::DataPacket *PacketFactory::createSoundPacket(unsigned char soundId, bool music, bool repeat) noexcept
{
	Packet::DataPacket *dataPacket = new Packet::DataPacket;

	dataPacket->cmd = 0;
	dataPacket->data.sound.soundId = soundId;
	dataPacket->data.sound.music = music;
	dataPacket->data.sound.repeat = repeat;

	return dataPacket;
}
