#pragma once
#include "Item.hpp"
#include "Cart.hpp"
class ItemList {
private:
	Item* itemArr = nullptr;
	int itemArrCount;
	long idCounter;
public:
	ItemList();
	ItemList(const ItemList& rhs);
	~ItemList();
	ItemList& operator=(const ItemList& rhs);

	void add(const Item& newItem);
	void remove(int index);

	//getters
	Item& getItem(int index) const;
	Item& getItemById(int id) const;
	int getItemArrCount() const;

	//other methods
	bool lookForId(int id) const;
	int indexOfItemBy(int search) const;
	bool takeItems(const Cart& cart);
};
