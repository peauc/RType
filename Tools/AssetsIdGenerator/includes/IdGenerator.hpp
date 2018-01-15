/*
** EPITECH PROJECT , 2020
** AssetsIdGenerator
** File description :
** No description
*/

#ifndef ASSETSIDGENERATOR_IDGENERATOR_HPP
#define ASSETSIDGENERATOR_IDGENERATOR_HPP

#include <vector>
#include <queue>
#include <string>

class IdGenerator {

private:

	using	Directories = std::queue<std::string>;
	using	Extensions = std::vector<std::string>;
	using 	AssetsId = std::vector<std::string>;

public:

	IdGenerator() = default;
	~IdGenerator() = default;
	IdGenerator(const IdGenerator&) = delete;
	IdGenerator		&operator=(const IdGenerator&) = delete;

	void	setRootDirectory(const std::string &rootDirectory);
	void	setDest(const std::string &dest);
	void	setExtensions(const Extensions &extensions);

	void	generateAssetsId();

private:

	void			addAssetsPath(const std::string &path);
	bool			isValidExtension(const std::string &extension) const;
	void			saveAssetsId() const;
	std::string		assetsIdFormat() const;
	std::string		jsonFormat(unsigned int id) const;

	std::string		rootDirectory;
	std::string		dest;

	Directories		directories;
	Extensions		extensions;
	AssetsId		assetsPath;


};


#endif //ASSETSIDGENERATOR_IDGENERATOR_HPP
