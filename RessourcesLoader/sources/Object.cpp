/*
** EPITECH PROJECT , 2020
** ParserJson
** File description :
** No description
*/

#include <algorithm>
#include "../includes/Object.hpp"

Object::Object(const std::string &data)
{
	this->data = data;
}

Object::Object(const Object &obj)
{
	this->data = obj.data;
	this->properties = obj.properties;
}

Object &Object::operator=(const Object &obj)
{
	if (&obj != this)
	{
		this->data = obj.data;
		this->properties = obj.properties;
	}
	return (*this);
}

void Object::loadProperties(const JsonDataLoader &loader)
{
	this->properties = loader.extractProperties(this->data);
}

void Object::setProperty(const JsonDataLoader::Property &property)
{
	auto	itProperty = std::find_if(this->properties.begin(),
									  this->properties.end(),
									  [property](const JsonDataLoader::Property &aProperty)
									  { return (aProperty.name == property.name); } );

	if (itProperty == this->properties.end())
		this->properties.push_back(property);
	else
		(*itProperty) = property;
}

std::string Object::getPropertyString(const std::string &propertyName) const
{
	for (auto &property : this->properties)
	{
		if (property.name == propertyName)
		{
			return (property.propertyValue);
		}
	}
	return ("");
}

int Object::getPropertyInt(const std::string &propertyName) const
{
	return (std::stoi(getPropertyString(propertyName)));
}

unsigned int Object::getPropertyUint(const std::string &propertyName) const
{
	return (static_cast<unsigned int>(std::stoi(getPropertyString(propertyName))));
}

bool Object::getPropertyBool(const std::string &propertyName) const
{
	return (getPropertyString(propertyName) == "true");
}
