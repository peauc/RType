/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include <boost/filesystem.hpp>
#include "AContainer.hpp"
#include "DuplicableItem.hpp"
#include "EnemiesListModel.hpp"

EnemiesListModel::EnemiesListModel(const std::string &directory,
								   AContainer *parent,
								   AContainer *employer) : AModel(parent) {
	this->directory = directory;
	this->employer = employer;
}

void EnemiesListModel::loadDataModel() {
	boost::filesystem::path		p(directory);

	if (!boost::filesystem::exists(p) || !boost::filesystem::is_directory(p))
		return;
	for (boost::filesystem::directory_entry& x
			: boost::filesystem::directory_iterator(p)) {
		if (boost::filesystem::is_regular_file(x.path())
			&& x.path().extension() == ".png")
			this->addChildToContainer(x.path().string());
	}
}

void EnemiesListModel::addChildToContainer(const std::string &imagePath) {
	this->container->addChild(new DuplicableItem(imagePath,
												 this->container,
												 this->employer));
}

