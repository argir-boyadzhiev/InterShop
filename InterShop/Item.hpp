#pragma once
#include "PropertyList.h"

class Item {

private:
	int id;
	char* name = nullptr;
	char* description = nullptr;
	double price;
	double quantity;
	bool countable;
	PropertyList properties;

public:
	Item();
	Item(int id, const char* name, const char* description, double price, double quantity, bool countable, const PropertyList& properties);
	Item(const Item& rhs);
	~Item();
	Item& operator=(const Item& rhs);

	//setters
	void setId(int newId);
	void setName(const char* newName);
	void setDescription(const char* newDescription);
	void setPrice(double newPrice);
	void setQuantity(double newQuantity);

	//getters
	int getId() const;
	const char* getName() const;
	const char* getDescription() const;
	double getPrice() const;
	double getQuantity() const;
	bool getCountable() const;
	const PropertyList& getProperties() const;

	//other methods
	void takeFromStock(double taken);
	void addToStock(double added);
};