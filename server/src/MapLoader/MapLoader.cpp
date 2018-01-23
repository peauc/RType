/*
** EPITECH PROJECT , 2020
** AssetsIdGenerator
** File description :
** No description
*/

#include "MapLoader.hpp"

const MapLoader::Zones &
MapLoader::loadZones(const std::string &filePath)
{
	std::vector<std::string> objects;
	JsonDataLoader::ArrayValues zones;

	if (!this->loader.loadFile(filePath))
		return (this->zones);
	objects = this->loader.extractObjects();
	for (auto &objectString : objects) {
		Object object(objectString);

		object.loadProperties(this->loader);
		this->mapWidth = object.getPropertyUint("Screen Width");
		this->mapHeight = object.getPropertyUint("Screen Height");
		zones = this->loader
				.extractArrayValues(object.getPropertyString("Zones"));
		this->browseZones(zones);
	}
	return (this->zones);
}

void MapLoader::browseZones(JsonDataLoader::ArrayValues &zones)
{
	Vector2d topLeftCoords;
	Vector2d bottomRightCoords;
	JsonDataLoader::ArrayValues childs;

	for (auto &zoneString : zones.values) {
		Object object(zoneString);

		object.loadProperties(this->loader);
		topLeftCoords.x = object.getPropertyUint("X1");
		topLeftCoords.y = object.getPropertyUint("Y1");
		bottomRightCoords.x = object.getPropertyUint("X2");
		bottomRightCoords.y = object.getPropertyUint("Y2");
		this->zones.emplace_back
				(Engine::Zone(topLeftCoords, bottomRightCoords));
		childs = this->loader
				.extractArrayValues(object.getPropertyString("Childs"));
		this->fillLastZone(childs);
	}
}

void MapLoader::fillLastZone(JsonDataLoader::ArrayValues &childs)
{
	std::string libName;
	Vector2d pos;

	for (auto &childString : childs.values) {
		Object object(childString);

		object.loadProperties(this->loader);
		libName = object.getPropertyString("Path");
		pos.x = object.getPropertyUint("X");
		pos.y = object.getPropertyUint("Y");
		this->zones.back().addZoneObject
				(Engine::Zone::ZoneObject(libName, pos));
	}
}

const MapLoader::Zones &MapLoader::getZones() const
{
	return (this->zones);
}

unsigned int MapLoader::getMapWidth() const
{
	return (this->mapWidth);
}

unsigned int MapLoader::getMapHeight() const
{
	return (this->mapHeight);
}
