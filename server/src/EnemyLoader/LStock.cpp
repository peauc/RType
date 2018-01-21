//
// Created by buis_p on 1/17/18.
//

#include <iostream>
#include <fstream>
#include <dirent.h>
#include <EnemyLoader/LStock.hpp>

void	LStock::loadByPath() {
	int				i = 0;
	DIR				*dir;
	struct dirent	*p;
	std::string		s;

	dir = opendir(this->path.c_str());
	if (dir) {
		while ((p = readdir(dir)) != nullptr) {
			s = p->d_name;
			if (s.find(".so") != s.npos) {
//				s = this->path + p->d_name;
				this->libList.push_back(s);
				if (i == 0)
					this->it = this->libList.begin();
				i++;
			}
		}
		closedir(dir);
	}
	else
		std::cout << "Error openning DLEnemies folder" << std::endl;
}

LStock::LStock(LStock const &other) {
	this->libList = other.libList;
	this->it = other.it;
}

const std::vector<std::string>	&LStock::getList() const {
	return (this->libList);
}

void LStock::setPath(const std::string &path) {
	this->path = path;
}
