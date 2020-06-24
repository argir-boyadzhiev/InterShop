#include "ItemList.hpp"

ItemList::ItemList()
{
	itemArr = new Item[0];
	itemArrCount = 0;
	idCounter = 0;
}

ItemList::ItemList(const ItemList& rhs)
{
	idCounter = 0;
	itemArrCount = rhs.getItemArrCount();
	itemArr = new Item[itemArrCount];
	for (int i = 0; i < itemArrCount; i++) {
		itemArr[i] = rhs.getItem(i);
		itemArr[i].setId(idCounter);
		idCounter++;
	}
}

ItemList::~ItemList()
{
	delete[] itemArr;
}

ItemList& ItemList::operator=(const ItemList& rhs)
{
	itemArrCount = rhs.getItemArrCount();
	delete[] itemArr;
	itemArr = new Item[itemArrCount];
	for (int i = 0; i < itemArrCount; i++) {
		itemArr[i] = rhs.getItem(i);
	}

	return *this;
}

void ItemList::add(const Item& newItem)
{
	itemArrCount++;
	Item* newItemArr = new Item[itemArrCount];

	for (int i = 0; i < itemArrCount-1; i++) {
		newItemArr[i] = itemArr[i];
	}
	newItemArr[itemArrCount - 1] = newItem;
	newItemArr[itemArrCount - 1].setId(idCounter);
	idCounter++;
	delete[] itemArr;
	itemArr = newItemArr;
}

void ItemList::remove(int index)
{
	itemArrCount--;
	Item* newItemArr = new Item[itemArrCount];

	for (int i = 0; i < index; i++) {
		newItemArr[i] = itemArr[i];
	}
	
	for (int i = index; i < itemArrCount; i++) {
		newItemArr[i] = itemArr[i + 1];
	}

	delete[] itemArr;
	itemArr = newItemArr;
}

Item& ItemList::getItem(int index) const
{
	return itemArr[index];
}

Item& ItemList::getItemById(int id) const
{
	for (int i = 0; i < itemArrCount; i++) {
		if (itemArr[i].getId() == id) {
			return itemArr[i];
		}
	}
}

bool ItemList::lookForId(int id) const
{
	for (int i = 0; i < itemArrCount; i++) {
		if (itemArr[i].getId() == id) {
			return true;
		}
	}
	return false;
}

int ItemList::getItemArrCount() const
{
	return itemArrCount;
}

int ItemList::indexOfItemBy(int search) const
{
	for (int i = 0; i < itemArrCount; i++) {
		if (itemArr[i].getId() == search) {
			return i;
		}
	}
	return -1;
}

bool ItemList::takeItems(const Cart& cart)
{
	bool available = true;
	for (int i = 0; i < cart.getCartSize(); i++) {
		if (cart.getQuantity(i) > getItemById(cart.getId(i)).getQuantity()) {
			available = false;
			break;
		}
	}

	if (!available) {
		return false;
	}

	for (int i = 0; i < cart.getCartSize(); i++) {
		getItemById(cart.getId(i)).takeFromStock(cart.getQuantity(i));
	}
	return true;
}
