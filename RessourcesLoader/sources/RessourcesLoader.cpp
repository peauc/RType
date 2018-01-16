/*
** EPITECH PROJECT , 2020
** AssetsIdGenerator
** File description :
** No description
*/

#include "RessourcesLoader.hpp"

void RessourcesLoader::loadAnimations(const std::string &filePath) {
	this->load(filePath, ANIMATION);
}

void RessourcesLoader::loadSounds(const std::string &filePath) {
	this->load(filePath, SOUND);
}

void RessourcesLoader::load(const std::string &filePath,
							RessourcesLoader::AssetType type) {
	std::vector<std::string>	objects;
	JsonDataLoader::ArrayValues	assets;

	if (!this->loader.loadFile(filePath))
		return ;
	objects = this->loader.extractObjects();
	for (auto &objectString : objects) {
		Object	object(objectString);

		object.loadProperties(this->loader);
		assets = this->loader
				.extractArrayValues(object.getPropertyString("Assets"));
		this->browseAssets(assets, type);
	}
}

void RessourcesLoader::browseAssets(JsonDataLoader::ArrayValues &assets,
									RessourcesLoader::AssetType type) {
	unsigned int	id;
	std::string		filePath;

	for (auto &assetString : assets.values) {
		Object	object(assetString);

		object.loadProperties(this->loader);
		id = object.getPropertyUint("Id");
		filePath = object.getPropertyString("Asset");
		if (type == ANIMATION)
			this->loadAnimation(id, filePath);
		else if (type == SOUND)
			this->sounds.insert(std::make_pair(id, filePath));
	}
}

void RessourcesLoader::loadAnimation(unsigned int id,
									  const std::string &filePath) {
	std::vector<std::string>	objects;
	std::string					objectString;
	Animation					animation;

	if (!this->loader.loadFile(filePath))
		return ;
	objects = this->loader.extractObjects();
	if (!objects.empty()) {
		objectString = objects.at(0);
		Object	object(objectString);

		object.loadProperties(this->loader);
		this->fillAnimation(object.getPropertyString("Animation"), animation);
		this->animations.insert(std::make_pair(id, animation));
	}
}

void
RessourcesLoader::fillAnimation(const std::string &property,
								 RessourcesLoader::Animation &animation) {
	auto 			spritesString = this->loader.extractArrayValues(property);
	Texture			texture;

	for (auto &spriteString : spritesString.values) {
		Object	object(spriteString);

		object.loadProperties(this->loader);
		texture.filePath = object.getPropertyString("File");
		texture.left = object.getPropertyInt("x");
		texture.top = object.getPropertyInt("y");
		texture.width = object.getPropertyInt("width");
		texture.height = object.getPropertyInt("height");
		animation.push_back(texture);
	}
}

const RessourcesLoader::Animations &RessourcesLoader::getAnimations() const {
	return (this->animations);
}

const RessourcesLoader::Sounds &RessourcesLoader::getSounds() {
	return (this->sounds);
}
