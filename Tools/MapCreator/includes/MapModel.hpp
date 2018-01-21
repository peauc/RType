/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_MAPMODEL_HPP
#define MAPCREATOR_MAPMODEL_HPP

#include "ChildMap.hpp"
#include "AContainer.hpp"
#include "AModel.hpp"

class MapModel : public AModel {

public:

	MapModel(AContainer *parent);
	~MapModel() = default;
	MapModel(const MapModel&) = delete;
	MapModel	&operator=(const MapModel&) = delete;

	void	setOutputDirectory(const std::string &outputDirectory);
	void	setExecDirectory(const std::string &execDirectory);
	void	setExistingMap(const std::string &existingMap);

	virtual void	loadDataModel();
	virtual void	saveMap() const;

protected:

	AContainer			*parent;

	std::string			outputDirectory;
	std::string			execDirectory;
	std::string			existingMap;


private:

	bool	inZone(const ChildMap *zone, const ChildMap *child) const;

	std::string		saveChilds() const;
	std::string		saveZone(const ChildMap *zone) const;
	std::string		zoneParams(const ChildMap *zone) const;
	std::string		saveChildInZone(const ChildMap *child) const;
};


#endif //MAPCREATOR_MAPMODEL_HPP
