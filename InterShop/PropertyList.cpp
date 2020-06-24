#include "PropertyList.h"

PropertyList::PropertyList()
{
	properties = new Property[0];
	lenght = 0;
}

void PropertyList::operator=(const PropertyList& rhs)
{
	lenght = rhs.getLenght();
	delete[] properties;
	properties = new Property[lenght];
	for (int i = 0; i < lenght; i++) {
		properties[i] = rhs.getPropertyByIndex(i);
	}
}

PropertyList::~PropertyList()
{
	delete[] properties;
}

void PropertyList::add(const Property& newProperty)
{
	Property* buffer = new Property[lenght + 1];
	for (int i = 0; i < lenght; i++) {
		buffer[i] = properties[i];
	}
	buffer[lenght] = newProperty;
	lenght++;
	delete[] properties;
	properties = buffer;
}

void PropertyList::removeByIndex(int index)
{
	lenght--;
	Property* buffer = new Property[lenght];
	for (int i = 0; i < index; i++) {
		buffer[i] = properties[i];
	}
	for (int i = index + 1; i < lenght; i++) {
		buffer[i] = properties[i];
	}
	delete[] properties;
	properties = buffer;
}

void PropertyList::removeAll()
{
	lenght = 0;
	delete[] properties;
	properties = new Property[0];
}

int PropertyList::getLenght() const
{
	return lenght;
}

const Property& PropertyList::getPropertyByIndex(int index) const
{
	return properties[index];
}
