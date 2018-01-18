//
// Created by romain on 18/01/18.
//

#ifndef RTYPE_PACKETFACTORY_HPP
#define RTYPE_PACKETFACTORY_HPP

#include <DataPacket.hpp>
#include <vector>

class PacketFactory
{
public:
	Packet::DataPacket createObjectPacket(short x, short y, Packet::EntityState entityState, bool hit, unsigned int id,
										  unsigned char animationId);
	Packet::DataPacket createScorePacket(Packet::GameState gameState,
										 const std::vector<Packet::PlayerScore> &playerScores);
};

#endif //RTYPE_PACKETFACTORY_HPP