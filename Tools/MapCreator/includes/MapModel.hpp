/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_MAPMODEL_HPP
#define MAPCREATOR_MAPMODEL_HPP

#include "JsonDataLoader.hpp"
#include "ChildMap.hpp"
#include "AModel.hpp"

class MapView;
class Object;

class MapModel : public AModel {

public:

	MapModel(MapView *parent);
	~MapModel() = default;
	MapModel(const MapModel&) = delete;
	MapModel	&operator=(const MapModel&) = delete;

	void	setEnemiesDirectory(const std::string &enemiesDirectory);
	void	setOutputDirectory(const std::string &outputDirectory);
	void	setExistingMap(const std::string &existingMap);

	virtual void	loadDataModel();
	virtual void	saveMap() const;

protected:

	MapView				*parent;
	JsonDataLoader		loader;

	std::string			enemiesDirectory;
	std::string			outputDirectory;
	std::string			existingMap;


private:

	bool	inZone(const ChildMap *zone, const ChildMap *child) const;

	void			loadZones();
	void			browseZones(JsonDataLoader::ArrayValues &zones);
	void			fillZone(JsonDataLoader::ArrayValues &childs);

	void			sendZone(const Object &object);
	void			sendObject(const Object &object);

	std::string		saveChilds() const;
	std::string		saveZone(const ChildMap *zone) const;
	std::string		zoneParams(const ChildMap *zone) const;
	std::string		saveChildInZone(const ChildMap *child) const;
	int				getRealXValue(int x) const;
	int				getRealYValue(int y) const;
};


#endif //MAPCREATOR_MAPMODEL_HPP
