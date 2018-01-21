/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_AMODEL_HPP
#define MAPCREATOR_AMODEL_HPP

#include <SFML/Graphics.hpp>

class AContainer;

class AModel {

public:

	AModel(AContainer *container = nullptr);
	virtual ~AModel() = default;
	AModel(const AModel&) = delete;
	AModel    &operator=(const AModel&) = delete;

	virtual void	loadDataModel() = 0;

protected:

	AContainer	*container;

};


#endif //MAPCREATOR_AMODEL_HPP
