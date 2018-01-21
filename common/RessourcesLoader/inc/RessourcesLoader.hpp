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

	RessourcesLoader() = default;
	~RessourcesLoader() = default;
	RessourcesLoader(const RessourcesLoader&) = delete;
	RessourcesLoader	&operator=(const RessourcesLoader&) = delete;

	void				loadAnimations(const std::string &filePath);
	const Animations	&getAnimations() const;
	void				loadSounds(const std::string &filePath);
	const Sounds		&getSounds();

private:

	JsonDataLoader		loader;
	Animations 			animations{};
	Sounds 				sounds{};

	void	load(const std::string &filePath, AssetType type);
	void	browseAssets(JsonDataLoader::ArrayValues &assets, AssetType type);
	void	loadAnimation(unsigned int id, const std::string &filePath);
	void	fillAnimation(const std::string &property, Animation &animation);

};


#endif //ASSETSIDGENERATOR_RESSOURCESLOADER_HPP
