/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include <iostream>
#include <fstream>
#include "PathResolver.hpp"
#include "MapModel.hpp"

MapModel::MapModel(AContainer *parent) : AModel(parent) {
	this->parent = parent;
}

void MapModel::loadDataModel() {

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

	result += indent + "\"X1\" : " + std::to_string(zone->getX()) + ",";
	result += indent + "\"Y1\" : " + std::to_string(zone->getY()) + ",";
	result += indent + "\"X2\" : " + std::to_string(zone->getX()
													+ zone->getWidth() - 1)
			  + ",";
	result += indent + "\"Y2\" : " + std::to_string(zone->getY()
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
	result += "\"X\" : " + std::to_string(child->getX() + child->getWidth() / 2)
			  + ", ";
	result += "\"Y\" : " + std::to_string(child->getY() + child->getHeight() / 2);
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
