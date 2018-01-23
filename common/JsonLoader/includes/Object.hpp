/*
** EPITECH PROJECT , 2020
** ParserJson
** File description :
** No description
*/

#ifndef JSONPARSER_OBJECT_HPP
#define JSONPARSER_OBJECT_HPP

#include "JsonDataLoader.hpp"

class Object
{
	std::string 							data;
	std::vector<JsonDataLoader::Property>	properties;

  public:

	void		loadProperties(const JsonDataLoader &loader);
	void 		setProperty(const JsonDataLoader::Property &property);

	std::string 	getPropertyString(const std::string &propertyName) const;
	int 			getPropertyInt(const std::string &propertyName) const;
	unsigned int 	getPropertyUint(const std::string &propertyName) const;
	bool 			getPropertyBool(const std::string &propertyName) const;

	explicit Object(const std::string &data = "");
	~Object() = default;
	Object(const Object &obj);
	Object	&operator=(const Object &obj);
};


#endif //JSONPARSER_OBJECT_HPP
