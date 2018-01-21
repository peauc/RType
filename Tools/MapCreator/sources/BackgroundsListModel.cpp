/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "AContainer.hpp"
#include "MapBackgroundItem.hpp"
#include "BackgroundsListModel.hpp"

BackgroundsListModel::BackgroundsListModel(const std::string &directory,
										   AContainer *parent,
										   AContainer *employer)
		: AListModel(parent) {
	this->directory = directory;
	this->employer = employer;
}

void BackgroundsListModel::loadDataModel() {
	boost::filesystem::path		p(directory);

	if (!boost::filesystem::exists(p) || !boost::filesystem::is_directory(p))
		return;
	for (boost::filesystem::directory_entry& x
			: boost::filesystem::directory_iterator(p)) {
		if (boost::filesystem::is_regular_file(x.path())
			&& x.path().extension() == ".png"
			|| x.path().extension() == ".jpeg"
			|| x.path().extension() == ".jpg")
			this->addChildToContainer(x.path().string());
	}
}

void BackgroundsListModel::addChildToContainer(const std::string &imagePath) {
	this->container->addChild(new MapBackgroundItem(imagePath,
													this->container,
													this->employer));
}
