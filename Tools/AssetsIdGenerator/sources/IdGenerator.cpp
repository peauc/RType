/*
** EPITECH PROJECT , 2020
** AssetsIdGenerator
** File description :
** No description
*/

#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include "PathResolver.hpp"
#include "IdGenerator.hpp"

void IdGenerator::setRootDirectory(const std::string &rootDirectory) {
	this->rootDirectory = rootDirectory;
}

void IdGenerator::setDest(const std::string &dest) {
	this->dest = dest;
}

void IdGenerator::setOrigin(const std::string &origin) {
	this->origin = PathResolver::changeOriginPath(origin);
}

void IdGenerator::setExtensions(const Extensions &extensions) {
	this->extensions = extensions;
}

void IdGenerator::generateAssetsId() {
	this->addAssetsPath(this->rootDirectory);
	while (!this->directories.empty()) {
		this->addAssetsPath(this->directories.front());
		this->directories.pop();
	}
	this->saveAssetsId();
}

void IdGenerator::addAssetsPath(const std::string &directoryPath) {
	boost::filesystem::path		p(directoryPath);

	if (!boost::filesystem::exists(p) || !boost::filesystem::is_directory(p))
		return;
	for (boost::filesystem::directory_entry& x
			: boost::filesystem::directory_iterator(p)) {
		if (boost::filesystem::is_regular_file(x.path())
			&& this->isValidExtension(boost::filesystem::extension(x.path())))
			this->assetsPath.push_back(x.path().string());
		else if (boost::filesystem::is_directory(x.path()))
			this->directories.push(x.path().string());
	}
}

bool IdGenerator::isValidExtension(const std::string &extension) const {
	if (this->extensions.empty())
		return (true);
	for (auto &ext : this->extensions) {
		if (ext == extension)
			return (true);
	}
	return (false);
}

void IdGenerator::saveAssetsId() const {
	std::string		filePath = this->dest + "AssetsId.txt";
	std::ofstream 	file(filePath, std::ios::out);

	if (file) {
		file << this->assetsIdFormat();
		file.close();
	} else
		std::cerr << "Can't open file : " << filePath << std::endl;
}

std::string IdGenerator::assetsIdFormat() const {
	std::string     format;

	format = "{";
	format += "\n\t Assets : ";
	format += "\n\t\t[";
	for (unsigned int id = 0; id < this->assetsPath.size(); ++id) {
		format += "\n\t\t\t";
		format += this->jsonFormat(id);
		format += ",";
	}
	if (!format.empty() && !this->assetsPath.empty())
		format.erase(--(format.end()));
	format += "\n\t\t]\n}";
	return (format);
}

std::string IdGenerator::jsonFormat(unsigned int id) const {
	std::string format;

	format = "{";
	format += " Asset : \"" + this->origin + this->assetsPath.at(id) + "\",";
	format += " Id : " + std::to_string(id);
	format += " }";
	return (format);
}
