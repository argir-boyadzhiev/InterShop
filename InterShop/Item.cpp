#include <iostream>
#include <string>
#include "HelpFunctions.hpp"
#include "Item.hpp"

Item::Item()
{
	id = 0;

	name = new char[1];
	name[0] = 0;

	description = new char[1];
	description[0] = 0;

	price = 0;
	quantity = 0;
	countable = true;
}

Item::Item(int id, const char* name, const char* description, double price, double quantity, bool countable, const PropertyList& properties)
{
	this->name = new char[1];
	this->name[0] = 0;

	this->description = new char[1];
	this->description[0] = 0;

	setId(id);
	setName(name);
	setDescription(description);
	setPrice(price);
	setQuantity(quantity);
	this->countable = countable;

	this->properties = properties;
}

Item::Item(const Item& rhs)
{
	setId(rhs.getId());
	setName(rhs.getName());
	setDescription(rhs.getDescription());
	setPrice(rhs.getPrice());
	setQuantity(rhs.getQuantity());
	countable = rhs.getCountable();
	properties = rhs.getProperties();
}

Item::~Item()
{
	delete[] name;
	delete[] description;
}

Item& Item::operator=(const Item& rhs)
{
	setId(rhs.getId());
	setName(rhs.getName());
	setDescription(rhs.getDescription());
	setPrice(rhs.getPrice());
	setQuantity(rhs.getQuantity());
	countable = rhs.getCountable();
	properties = rhs.getProperties();
	return *this;
}

void Item::setId(int newId)
{
	id = newId;
}

void Item::setName(const char* newName)
{
	int lenght = strLen(newName);
	delete[] name;
	name = new char[lenght + 1];

	strCpy(name, newName);
}

void Item::setDescription(const char* newDescription)
{
	int lenght = strLen(newDescription);
	delete[] description;
	description = new char[lenght + 1];
	strCpy(description, newDescription);
}

void Item::setPrice(double newPrice)
{
	
	price = newPrice;
	
}

void Item::setQuantity(double newQuantity)
{
	quantity = newQuantity;
}

int Item::getId() const
{
	return id;
}

const char* Item::getName() const
{
	return name;
}

const char* Item::getDescription() const
{
	return description;
}

double Item::getPrice() const
{
	return price;
}

double Item::getQuantity() const
{
	return quantity;
}

bool Item::getCountable() const
{
	return countable;
}

const PropertyList& Item::getProperties() const
{
	return properties;
}

void Item::takeFromStock(double taken)
{
	quantity -= taken;
}

void Item::addToStock(double added)
{
	quantity += added;
}
