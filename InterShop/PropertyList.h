#pragma once
#include "Property.h"
class PropertyList
{
private:
	Property* properties;
	int lenght;
public:
	PropertyList();
	void operator=(const PropertyList& rhs);
	~PropertyList();

	void add(const Property& newProperty);
	void removeByIndex(int index);
	void removeAll();

	int getLenght() const;

	const Property& getPropertyByIndex(int index) const;
};

