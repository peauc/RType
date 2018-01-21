/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_BACKGROUNDSLISTMODEL_HPP
#define MAPCREATOR_BACKGROUNDSLISTMODEL_HPP

#include <boost/filesystem.hpp>
#include "AListModel.hpp"

class BackgroundsListModel : public AListModel {

public:

	BackgroundsListModel(const std::string &directory,
						 AContainer *container,
						 AContainer *employer);
	virtual ~BackgroundsListModel() = default;
	BackgroundsListModel(const BackgroundsListModel&) = delete;
	BackgroundsListModel	&operator=(const BackgroundsListModel&) = delete;

	virtual void	loadDataModel();

private:

	void	addChildToContainer(const std::string &imagePath);

	std::string		directory;
	AContainer		*employer;

};


#endif //MAPCREATOR_BACKGROUNDSLISTMODEL_HPP
