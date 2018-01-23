/*
** EPITECH PROJECT , 2020
** AssetsIdGenerator
** File description :
** No description
*/

#ifndef ASSETSIDGENERATOR_MAPLOADER_HPP
#define ASSETSIDGENERATOR_MAPLOADER_HPP

#include <string>
#include <vector>
#include "Zone.hpp"
#include "JsonDataLoader.hpp"
#include "Object.hpp"

class MapLoader
{

public:

	using Zones = std::vector<Engine::Zone>;

	MapLoader() = default;
	~MapLoader() = default;
	MapLoader(const MapLoader &) = delete;
	MapLoader &operator=(const MapLoader &) = delete;

	const Zones &loadZones(const std::string &filePath);
	const Zones &getZones() const;

	unsigned int getMapWidth() const;
	unsigned int getMapHeight() const;

private:

	JsonDataLoader loader;
	Zones zones;

	unsigned int mapWidth;
	unsigned int mapHeight;

	void browseZones(JsonDataLoader::ArrayValues &zones);
	void fillLastZone(JsonDataLoader::ArrayValues &childs);
};

#endif //ASSETSIDGENERATOR_MAPLOADER_HPP
