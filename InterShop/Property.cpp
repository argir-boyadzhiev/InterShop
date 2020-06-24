#include "Property.h"
#include "HelpFunctions.hpp"

Property::Property()
{
	name = new char[1];
	name[0] = 0;
	value = new char[1];
	value[0] = 0;
}

Property::Property(const char* newName, const char* newValue)
{
	name = new char[strLen(newName) + 1];
	strCpy(name, newName);
	value = new char[strLen(newValue) + 1];
	strCpy(value, newValue);
}

Property::~Property()
{
	delete[] name;
	delete[] value;
}

void Property::operator=(const Property& rhs)
{
	delete[] name;
	name = new char[strLen(rhs.getName()) + 1];
	strCpy(name, rhs.getName());

	delete[] value;
	value = new char[strLen(rhs.getValue()) + 1];
	strCpy(value, rhs.getValue());
}

const char* Property::getName() const
{
	return name;
}

const char* Property::getValue() const
{
	return value;
}
