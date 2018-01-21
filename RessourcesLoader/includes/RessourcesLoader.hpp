/*
** EPITECH PROJECT , 2020
** AssetsIdGenerator
** File description :
** No description
*/

#ifndef ASSETSIDGENERATOR_RESSOURCESLOADER_HPP
#define ASSETSIDGENERATOR_RESSOURCESLOADER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "Zone.hpp"
#include "Texture.hpp"
#include "JsonDataLoader.hpp"
#include "Object.hpp"

class RessourcesLoader {

private:

	enum AssetType {
		ANIMATION,
		SOUND
	};

public:
	using Animation = std::vector<Texture>;
	using Animations = std::unordered_map<unsigned int, Animation>;
	using Sounds = std::unordered_map<unsigned int, std::string>;
	using Zones = std::vector<Engine::MapLoader::Zone>;

	RessourcesLoader() = default;
	~RessourcesLoader() = default;
	RessourcesLoader(const RessourcesLoader&) = delete;
	RessourcesLoader	&operator=(const RessourcesLoader&) = delete;

	void				loadAnimations(const std::string &filePath);
	const Animations	&getAnimations() const;
	void				loadSounds(const std::string &filePath);
	const Sounds		&getSounds();
	const Zones			&loadZones(const std::string &filePath);
	const Zones			&getZones() const;

private:

	JsonDataLoader		loader;
	Animations 			animations;
	Sounds 				sounds;
	Zones				zones;

	void	load(const std::string &filePath, AssetType type);
	void	browseAssets(JsonDataLoader::ArrayValues &assets, AssetType type);
	void	loadAnimation(unsigned int id, const std::string &filePath);
	void	fillAnimation(const std::string &property, Animation &animation);

	void	browseZones(JsonDataLoader::ArrayValues &zones);
	void	fillLastZone(JsonDataLoader::ArrayValues &childs);

};


#endif //ASSETSIDGENERATOR_RESSOURCESLOADER_HPP
