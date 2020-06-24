#pragma once
#include "Item.hpp"
class Cart {
private:
	long* ids = nullptr;
	double* quantities = nullptr;
	int cartSize;
public:
	Cart();
	Cart(const Cart& rhs);
	~Cart();
	Cart& operator=(const Cart& rhs);

	//
	void add(long id, double quantity);
	void remove(int index);
	void empty();

	//getters
	long getId(int index) const;
	double getQuantity(int index) const;
	int getCartSize() const;
	int getIndexById(int id) const;
};
