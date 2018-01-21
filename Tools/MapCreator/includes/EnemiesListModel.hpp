/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_ENEMIESLISTMODEL_HPP
#define MAPCREATOR_ENEMIESLISTMODEL_HPP

#include <boost/filesystem.hpp>
#include "AListModel.hpp"

class EnemiesListModel : public AListModel {

public:

	EnemiesListModel(const std::string &directory,
					 AContainer *container, AContainer *employer);
	virtual ~EnemiesListModel() = default;
	EnemiesListModel(const EnemiesListModel&) = delete;
	EnemiesListModel		&operator=(const EnemiesListModel&) = delete;

	virtual void	loadDataModel();

private:

	void	addChildToContainer(const std::string &imagePath);

	std::string		directory;
	AContainer		*employer;

};


#endif //MAPCREATOR_ENEMIESLISTMODEL_HPP
