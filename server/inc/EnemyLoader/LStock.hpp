//
// Created by skulrag on 1/17/18.
//

#ifndef RTYPE_LSTOCK_HPP
#define RTYPE_LSTOCK_HPP

#include <iostream>
#include <string>
#include <vector>

class   LStock {
private:
	std::vector<std::string> libList;
	std::vector<std::string>::const_iterator	it;
	std::string path;
public:
	void setPath(const std::string &path);

public:
	LStock();
	LStock(LStock const &other);
	LStock	&operator=(LStock const &other) = default;
	~LStock() = default;

	void							loadByPath();
	void							addLib(const std::string &path);
	const std::vector<std::string>	&getList() const;
};

#endif //RTYPE_LSTOCK_HPP
