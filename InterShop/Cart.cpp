#include "Cart.hpp"

Cart::Cart()
{
	cartSize = 0;
	ids = new long[0];
	quantities = new double[0];
}

Cart::Cart(const Cart& rhs)
{
	cartSize = rhs.getCartSize();
	ids = new long[cartSize];
	quantities = new double[cartSize];
	for (int i = 0; i < cartSize; i++) {
		ids[i] = rhs.getId(i);
		quantities[i] = rhs.getQuantity(i);
	}
}

Cart::~Cart()
{
	delete[] ids;
	delete[] quantities;
}

Cart& Cart::operator=(const Cart& rhs)
{
	cartSize = rhs.getCartSize();
	delete[] ids;
	ids = new long[cartSize];
	delete[] quantities;
	quantities = new double[cartSize];
	for (int i = 0; i < cartSize; i++) {
		ids[i] = rhs.getId(i);
		quantities[i] = rhs.getQuantity(i);
	}

	return *this;
}

void Cart::add(long id, double quantity)
{
	for (int i = 0; i < cartSize; i++) {
		if (id == ids[i]) {
			quantities[i] += quantity;
			return;
		}
	}

	cartSize++;
	long* newIds = new long[cartSize];
	double* newQuantities = new double[cartSize];

	for (int i = 0; i < cartSize - 1; i++) {
		newIds[i] = ids[i];
		newQuantities[i] = quantities[i];
	}
	newIds[cartSize - 1] = id;
	newQuantities[cartSize - 1] = quantity;
	delete[] ids;
	delete[] quantities;
	ids = newIds;
	quantities = newQuantities;
}

void Cart::remove(int index)
{
	cartSize--;
	long* newIds = new long[cartSize];
	double* newQuantities = new double[cartSize];

	for (int i = 0; i < index; i++) {
		newIds[i] = ids[i];
		newQuantities[i] = quantities[i];
	}
	for (int i = index; i < cartSize; i++) {
		newIds[i] = ids[i + 1];
		newQuantities[i] = quantities[i + 1];
	}

	delete[] ids;
	delete[] quantities;
	ids = newIds;
	quantities = newQuantities;
}

void Cart::empty()
{
	cartSize = 0;
	delete[] ids;
	delete[] quantities;
	ids = new long[0];
	quantities = new double[0];
}

long Cart::getId(int index) const
{
	if (index < cartSize) {
		return ids[index];
	}
	else {
		return -1;
	}
}


double Cart::getQuantity(int index) const
{
	if (index < cartSize) {
		return quantities[index];
	}
	else {
		return 0.0;
	}
}

int Cart::getCartSize() const
{
	return cartSize;
}

int Cart::getIndexById(int id) const
{
	for (int i = 0; i < cartSize; i++) {
		if (ids[i] == id) {
			return i;
		}
	}
	return -1;
}
