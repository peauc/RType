/*
** EPITECH PROJECT , 2020
** ParserJson
** File description :
** No description
*/

#include <iostream>
#include <fstream>
#include "../includes/JsonDataLoader.hpp"

JsonDataLoader::Type JsonDataLoader::resolveType(char ref) const
{
	switch (ref)
	{
		case '{' :
			return (Type::OBJECT);
		case '[' :
			return (Type::ARRAY);
		case '\"' :
			return (Type::STRING);
		case 't' :
			return (Type::TRUE);
		case 'f' :
			return (Type::FALSE);
		case 'n' :
			return (Type::EMPTY);
		default :
			return (Type::NUMBER);
	}
}

std::string JsonDataLoader::stringWithoutQuotes(const std::string &ref) const
{
	std::string		result = onlyString(ref);

	if (!result.empty() && result.front() == '\"')
		result.erase(result.begin());
	if (!result.empty() && result.back() == '\"')
		result.erase(--result.end());
	return (result);
}

std::string JsonDataLoader::onlyString(const std::string &ref) const
{
	std::string 	result = ref;

	while (!result.empty() && (result.front() == ' ' || result.front() == '\t'
							   || result.front() == '\n'))
		result.erase(result.begin());
	while (!result.empty() && (result.back() == ' ' || result.back() == '\t'
							   || result.back() == '\n'))
		result.erase(--result.end());
	return (result);
}

std::string JsonDataLoader::getNextTopObject(const std::string &content,
											 unsigned int &index) const
{
	std::string 	object;
	int 			count = 1;

	while (index < content.size() && content.at(index) != '{')
		index++;
	index++;
	while (index < content.size() && (content.at(index) != '}' || count > 1)) {
		object += content.at(index);
		if (content.at(index) == '}')
			count--;
		else if (content.at(index) == '{')
			count++;
		index++;
	}
	return (object);
}

std::string JsonDataLoader::getNextTopProperty(const std::string &content,
											   unsigned int &index) const
{
	std::string 	property;
	int 			countOne = 1;
	int 			countTwo = 1;

	while (index < content.size() && (content.at(index) != ',' || countOne > 1
									  || countTwo > 1) && countOne > 0) {
		property += content.at(index);
		if (content.at(index) == '}')
			countOne--;
		else if (content.at(index) == '{')
			countOne++;
		if (content.at(index) == ']')
			countTwo--;
		else if (content.at(index) == '[')
			countTwo++;
		index++;
	}
	index++;
	return (property);
}

std::string JsonDataLoader::getNextTopArray(const std::string &content,
											unsigned int &index) const
{
	std::string 	array;
	int 			count = 1;

	while (index < content.size() && content.at(index) != '[')
		index++;
	index++;
	while (index < content.size() && (content.at(index) != ']' || count > 1)) {
		array += content.at(index);
		if (content.at(index) == ']')
			count--;
		else if (content.at(index) == '[')
			count++;
		index++;
	}
	return (array);
}

std::vector<std::string>
JsonDataLoader::splitProperty(const std::string &property) const
{
	std::vector<std::string>	elements(2);
	unsigned int				index = 0;

	while (index < property.size() && property.at(index) != ':')
		elements.at(0) += property.at(index++);
	++index;
	while (index < property.size())
		elements.at(1) += property.at(index++);
	elements.at(0) = stringWithoutQuotes(elements.at(0));
	elements.at(1) = stringWithoutQuotes(elements.at(1));
	return (elements);
}

bool JsonDataLoader::loadFile(const std::string &path)
{
	std::ifstream	file(path, std::ios::in);
	std::string 	line;

	if (file) {
		this->fileContent = "";
		while (std::getline(file, line))
			this->fileContent += line;
		file.close();
	} else {
		std::cerr << "Impossible d'ouvrir le fichier : " << path << std::endl;
		return (false);
	}
	return (true);
}

std::vector<std::string> JsonDataLoader::extractObjects() const
{
	std::vector<std::string>	objects;
	std::string 				objectProperties;
	unsigned int				index = 0;

	objectProperties = getNextTopObject(this->fileContent, index);
	while (!objectProperties.empty()) {
		objects.push_back(objectProperties);
		objectProperties = getNextTopObject(this->fileContent, index);
	}
	return (objects);
}

std::vector<JsonDataLoader::Property>
JsonDataLoader::extractProperties(const std::string &data) const
{
	std::vector<JsonDataLoader::Property>	properties;
	std::string 							propertyString;
	std::vector<std::string>				elements;
	unsigned int							index = 0;

	propertyString = getNextTopProperty(data, index);
	while (!propertyString.empty()) {
		elements = splitProperty(propertyString);
		if (!elements.at(0).empty() && !elements.at(1).empty())
			this->addProperty(properties, elements);
		propertyString = getNextTopProperty(data, index);
	}
	return (properties);
}

void
JsonDataLoader::addProperty(std::vector<JsonDataLoader::Property> &properties,
							const std::vector<std::string> &elements) const {
	JsonDataLoader::Property	property;
	unsigned int				nullIndex;

	property.name = elements.at(0);
	nullIndex = 0;
	property.valueType = resolveType(elements.at(1).at(0));
	if (property.valueType == Type::OBJECT)
		property.propertyValue = getNextTopObject(elements.at(1), nullIndex);
	else if (property.valueType == Type::ARRAY)
		property.propertyValue = getNextTopArray(elements.at(1), nullIndex);
	else
		property.propertyValue = elements.at(1);
	properties.push_back(property);
}

JsonDataLoader::ArrayValues
JsonDataLoader::extractArrayValues(const std::string &data) const
{
	JsonDataLoader::ArrayValues		arrayValues;
	std::string 					arrayValueString = onlyString(data);

	arrayValues.valuesType = Type::EMPTY;
	if (!arrayValueString.empty() && arrayValueString.at(0) != ',')
		this->addArrayValue(arrayValues, arrayValueString);
	for (auto it = arrayValues.values.begin(); it != arrayValues.values.end();)
		it = ((*it).empty() ? arrayValues.values.erase(it) : ++it);
	return (arrayValues);
}

void JsonDataLoader::addArrayValue(JsonDataLoader::ArrayValues &arrayValues,
								   const std::string &arrayValueString) const {
	unsigned int	index = 0;

	arrayValues.valuesType = resolveType(arrayValueString.at(0));
	if (arrayValues.valuesType == Type::OBJECT)
		while (index < arrayValueString.size())
			arrayValues.values
					.push_back(getNextTopObject(arrayValueString, index));
	else if (arrayValues.valuesType == Type::ARRAY)
		while (index < arrayValueString.size())
			arrayValues.values
					.push_back(getNextTopArray(arrayValueString, index));
	else
		while (index < arrayValueString.size())
			arrayValues.values
					.push_back(getNexArrayElement(arrayValueString, index));
}

std::string JsonDataLoader::getNexArrayElement(const std::string &content,
											   unsigned int &index) const
{
	std::string 	element;

	while (index < content.size() && content.at(index) != ',')
		element += content.at(index++);
	++index;
	return (stringWithoutQuotes(element));
}
