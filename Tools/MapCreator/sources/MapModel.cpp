/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include <iostream>
#include <fstream>
#include "Object.hpp"
#include "MapView.hpp"
#include "PathResolver.hpp"
#include "MapModel.hpp"

MapModel::MapModel(MapView *parent) : AModel(parent) {
	this->parent = parent;
}

void MapModel::setOutputDirectory(const std::string &outputDirectory) {
	this->outputDirectory = outputDirectory;
	if (!this->outputDirectory.empty() && this->outputDirectory.back() != '/')
		this->outputDirectory += "/";
}

void MapModel::setExecDirectory(const std::string &execDirectory) {
	this->execDirectory = PathResolver::changeOriginPath(execDirectory);
}

void MapModel::setExistingMap(const std::string &existingMap) {
	this->existingMap = existingMap;
}

void MapModel::loadDataModel() {
	this->loadZones();
}

void MapModel::loadZones() {
	std::vector<std::string>	objects;
	JsonDataLoader::ArrayValues	zones;

	if (!this->loader.loadFile(this->existingMap))
		return ;
	objects = this->loader.extractObjects();
	for (auto &objectString : objects) {
		Object	object(objectString);

		object.loadProperties(this->loader);
		zones = this->loader
				.extractArrayValues(object.getPropertyString("Zones"));
		this->browseZones(zones);
	}
}

void MapModel::browseZones(JsonDataLoader::ArrayValues &zones) {
	JsonDataLoader::ArrayValues	childs;

	for (auto &zoneString : zones.values) {
		Object	object(zoneString);

		object.loadProperties(this->loader);
		this->sendZone(object);
		childs = this->loader
				.extractArrayValues(object.getPropertyString("Childs"));
		this->fillZone(childs);
	}
}

void MapModel::fillZone(JsonDataLoader::ArrayValues &childs) {
	std::string								libName;

	for (auto &childString : childs.values) {
		Object	object(childString);

		object.loadProperties(this->loader);
		this->sendObject(object);
	}
}

void MapModel::sendZone(const Object &object) {
	ChildMap	*zone = new ChildMap;

	zone->setX(object.getPropertyUint("X1"));
	zone->setY(object.getPropertyUint("Y1"));
	zone->setWidth(object.getPropertyUint("X2") - zone->getX());
	zone->setHeight(object.getPropertyUint("Y2") - zone->getY());
	zone->setResizing(false);
	this->parent->loadChild(zone);
}

void MapModel::sendObject(const Object &object) {
	ChildMap	*child = new ChildMap(nullptr, object.getPropertyString("Path"));

	child->setPathItem(object.getPropertyString("Path"));
	child->setWidth(object.getPropertyUint("Width"));
	child->setHeight(object.getPropertyUint("Height"));
	child->setX(object.getPropertyUint("X") - child->getWidth() / 2);
	child->setY(object.getPropertyUint("Y") - child->getHeight() / 2);
	this->parent->loadChild(child);
}

void MapModel::saveMap() const {
	std::string     filePath;

	filePath = this->outputDirectory + "Game.map";
	std::cout << "filePath : " << filePath << std::endl;
	std::ofstream file(filePath, std::ios::out);
	if (file) {
		file << this->saveChilds();
		file.close();
	} else
		std::cerr << "Can't open file : " << filePath << std::endl;
}

std::string MapModel::saveChilds() const {
	auto			&childs = this->parent->getChilds();
	std::string		result;

	result = "{\n";
	result += "\t\"Screen Width\" : "
			  + std::to_string(this->parent->getWidth()) +"\n";
	result += "\t\"Screen Height\" : "
			  + std::to_string(this->parent->getHeight()) + "\n";
	result += "\t\"Zones\" : \n";
	result += "\t\t[";
	for (auto &child : childs) {
		auto	*upChild = dynamic_cast<ChildMap*>(child.get());

		if (upChild->getPathItem().empty())
			result += "\n" + this->saveZone(upChild) + ",";
	}
	if (result.back() == ',')
		result.erase(--result.end());
	result += "\n\t\t]\n";
	result += "\n}";
	return (result);
}

std::string MapModel::saveZone(const ChildMap *zone) const {
	auto			&childs = this->parent->getChilds();
	std::string		result;

	result = "\t\t\t{";
	result += zoneParams(zone);
	result += "\n\t\t\t\t\"Childs\" : \n";
	result += "\t\t\t\t\t[";
	for (auto &child : childs) {
		auto	*upChild = dynamic_cast<ChildMap*>(child.get());

		if (!upChild->getPathItem().empty() && this->inZone(zone, upChild))
			result += "\n" + this->saveChildInZone(upChild) + ",";
	}
	if (result.back() == ',')
		result.erase(--result.end());
	result += "\n\t\t\t\t\t]\n";
	result += "\n\t\t\t}";
	return (result);
}

std::string MapModel::zoneParams(const ChildMap *zone) const {
	std::string		result;
	std::string		indent = "\n\t\t\t\t";

	result += indent + "\"X1\" : "
			  + std::to_string(this->getRealXValue(zone->getX())) + ",";
	result += indent + "\"Y1\" : "
			  + std::to_string(this->getRealYValue(zone->getY())) + ",";
	result += indent + "\"X2\" : "
			  + std::to_string(this->getRealXValue(zone->getX())
							   + zone->getWidth() - 1) + ",";
	result += indent + "\"Y2\" : "
			  + std::to_string(this->getRealYValue(zone->getY())
							   + zone->getHeight() - 1)
			  + ",";
	return (result);
}

std::string MapModel::saveChildInZone(const ChildMap *child) const {
	std::string		result;
	std::string		indent = "\t\t\t\t\t\t";

	result = indent;
	result += "{ ";
	result += "\"Path\" : \"" + this->execDirectory + child->getPathItem()
			  + "\", ";
	result += "\"X\" : "
			  + std::to_string(this->getRealXValue(child->getX())
							   + child->getWidth() / 2) + ", ";
	result += "\"Y\" : "
			  + std::to_string(this->getRealYValue(child->getY())
							   + child->getHeight() / 2) + ", ";
	result += "\"Width\" : " + std::to_string(child->getWidth()) + ", ";
	result += "\"Height\" : " + std::to_string(child->getHeight());
	result += " }";
	return (result);
}

bool MapModel::inZone(const ChildMap *zone, const ChildMap *child) const {
	return (child->getX() >= zone->getX()
			&& (child->getX() + child->getWidth())
			   <= (zone->getX() + zone->getWidth())
			&& child->getY() >= zone->getY()
			&& (child->getY() + child->getHeight())
			   <= (zone->getY() + zone->getHeight()));
}

int MapModel::getRealXValue(int x) const {
	return (x - this->parent->getScrollValue() - this->parent->getX());
}

int MapModel::getRealYValue(int y) const {
	return (y - this->parent->getY());
}
