/*
** EPITECH PROJECT , 2020
** ParserJson
** File description :
** No description
*/

#ifndef JSONPARSER_JSONDATALOADER_HPP
#define JSONPARSER_JSONDATALOADER_HPP

#include <string>
#include <vector>

class JsonDataLoader
{

public:

	enum Type
	{
		STRING = 0,
		NUMBER,
		OBJECT,
		ARRAY,
		TRUE,
		FALSE,
		EMPTY
	};


	std::vector<std::string>	extractObjects() const ;

	struct Property
	{
		std::string		name;
		std::string 	propertyValue;
		Type 			valueType;
	};

	std::vector<JsonDataLoader::Property>	extractProperties(const std::string &data) const;

	struct ArrayValues
	{
		std::vector<std::string>	values;
		Type 						valuesType;
	};

	JsonDataLoader::ArrayValues	extractArrayValues(const std::string &data) const;

	bool			loadFile(const std::string &path);

	JsonDataLoader() = default;
	~JsonDataLoader() = default;
	JsonDataLoader(const JsonDataLoader&) = delete;
	JsonDataLoader	&operator=(const JsonDataLoader&) = delete;

private:

	JsonDataLoader::Type	resolveType(char ref) const;

	void		addProperty(std::vector<Property> &properties,
							const std::vector<std::string> &elements) const;
	void		addArrayValue(ArrayValues &arrayValues,
							  const std::string &arrayValueString) const;

	std::string			fileContent;

	std::string 		stringWithoutQuotes(const std::string &ref) const;
	std::string 		onlyString(const std::string &ref) const;

	std::string			getNextTopObject(const std::string &content,
											unsigned int &index) const;
	std::string			getNextTopProperty(const std::string &content,
											  unsigned int &index) const;
	std::string			getNextTopArray(const std::string &content,
										   unsigned int &index) const;
	std::string			getNexArrayElement(const std::string &content,
											  unsigned int &index) const;

	std::vector<std::string>	splitProperty(const std::string &property) const;

};


#endif //JSONPARSER_JSONDATALOADER_HPP
