/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#ifndef MAPPER_PATHRESOLVER_HPP
#define MAPPER_PATHRESOLVER_HPP

#include <boost/filesystem.hpp>
#include <queue>
#include <string>

class PathResolver {

public:

	PathResolver() = default;
	~PathResolver() = default;
	PathResolver(const PathResolver&) = delete;
	PathResolver	&operator=(const PathResolver&) = delete;

	static std::string	changeOriginPath(const std::string &newOrigin);

private:

	static void			changeCurrentDir(const std::string &newDir);

	static std::string
	transformPath(const boost::filesystem::path &currentPath,
				  const boost::filesystem::path &newPath);

	static void			removeSamePath(std::queue<std::string> &pCurrent,
										  std::queue<std::string> &pNew);

};


#endif //MAPPER_PATHRESOLVER_HPP
