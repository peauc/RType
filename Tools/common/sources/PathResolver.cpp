/*
** EPITECH PROJECT , 2020
** Mapper
** File description :
** No description
*/

#ifdef _WIN32
#include <direct.h>
#elif __unix__
#include <cstdlib>
#endif

#include "PathResolver.hpp"

std::string PathResolver::changeOriginPath(const std::string &newOrigin) {
	boost::filesystem::path		p(newOrigin);

	if (!boost::filesystem::exists(p) || !boost::filesystem::is_directory(p))
		return ("");

	auto	currentPath = boost::filesystem::current_path();

	changeCurrentDir(newOrigin);

	auto	newPath = boost::filesystem::current_path();

	changeCurrentDir(currentPath.string());
	return (transformPath(currentPath, newPath));
}

void PathResolver::changeCurrentDir(const std::string &newDir) {
#ifdef _WIN32
	_chdir(newDir.c_str());
#elif __unix__
	chdir(newDir.c_str());
#endif
}

std::string
PathResolver::transformPath(const boost::filesystem::path &currentPath,
							const boost::filesystem::path &newPath) {

	std::queue<std::string>	pCurrent;
	std::queue<std::string>	pNew;
	std::string				result = "";

	for (auto &seg : currentPath)
		pCurrent.push(seg.string());
	for (auto &seg : newPath)
		pNew.push(seg.string());
	removeSamePath(pCurrent, pNew);
	while (!pNew.empty()) {
		result += "../";
		pNew.pop();
	}
	while (!pCurrent.empty()) {
		result += pCurrent.front() + "/";
		pCurrent.pop();
	}
	return (result);
}

void PathResolver::removeSamePath(std::queue<std::string> &pCurrent,
								  std::queue<std::string> &pNew) {
	while (!pCurrent.empty() && !pNew.empty()
		   && pCurrent.front() == pNew.front()) {
		pCurrent.pop();
		pNew.pop();
	}
}
