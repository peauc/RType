/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_ALISTMODEL_HPP
#define MAPCREATOR_ALISTMODEL_HPP

#include <SFML/Graphics.hpp>

class AContainer;

class AListModel {

public:

	AListModel(AContainer *container = nullptr);
	virtual ~AListModel() = default;
	AListModel(const AListModel&) = delete;
	AListModel    &operator=(const AListModel&) = delete;

	virtual void	loadDataModel() = 0;

protected:

	AContainer	*container;

};


#endif //MAPCREATOR_ALISTMODEL_HPP
