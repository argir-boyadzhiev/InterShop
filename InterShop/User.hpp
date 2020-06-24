#pragma once
#include "Cart.hpp"

class User {
private:
	char* username = nullptr;
	char* password = nullptr;
	double money;
	Cart cart;
	bool admin;
	

public:
	User();
	User(const char* username, const char* password, double money, bool admin);
	~User();
	User& operator=(const User& rhs);

	
	//getters
	const char* getUsername() const;
	const char* getPassword() const;
	double getMoney() const;
	const Cart& getCart() const;
	bool getAdmin() const;

	//other methods
	bool tryPass(const char* pass);
	void addToCart(int id, double quantity);
	bool removeFromCart(int id);
	void changeMoney(double change);
	void emptyCart();
};
