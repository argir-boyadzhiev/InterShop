#pragma once
#include "User.hpp"
#include "HelpFunctions.hpp"
User::User()
{
	username = new char[1];
	username[0] = 0;
	password = new char[1];
	password[0] = 0;
	money = 0;
	admin = false;
}

User::User(const char* username, const char* password, double money, bool admin)
{
	this->username = new char[strLen(username) + 1];
	strCpy(this->username, username);

	this->password = new char[strLen(password) + 1];
	strCpy(this->password, password);

	this->money = money;

	this->admin = admin;
}

User::~User()
{
	delete[] username;
	delete[] password;
}

User& User::operator=(const User& rhs)
{
	delete[] username;
	delete[] password;

	username = new char[strLen(rhs.getUsername()) + 1];
	strCpy(username, rhs.getUsername());

	password = new char[strLen(rhs.getPassword()) + 1];
	strCpy(password, rhs.getPassword());

	money = rhs.getMoney();
	cart = rhs.getCart();
	admin = rhs.getAdmin();

	return *this;
}

const char* User::getUsername() const
{
	return username;
}

const char* User::getPassword() const
{
	return password;
}

double User::getMoney() const
{
	return money;
}

const Cart& User::getCart() const
{
	return cart;
}

bool User::getAdmin() const
{
	return admin;
}

bool User::tryPass(const char* pass)
{
	if (strCmp(pass, password) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void User::addToCart(int id, double quantity)
{
	cart.add(id, quantity);
}

bool User::removeFromCart(int id)
{
	int index = cart.getIndexById(id);
	if (index == -1) {
		return false;
	}
	else {
		cart.remove(index);
		return true;
	}
}

void User::changeMoney(double change)
{
	money += change;
}

void User::emptyCart()
{
	cart.empty();
}
