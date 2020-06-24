#pragma once
#include "UserList.hpp"
#include "ItemList.hpp"
class Shop {

private:
	UserList userList;
	int currentUser;
	ItemList itemList;
	char* fileName; //still in progress
	double money; //money of the shop

	//from startMenu
	void logInMenu();
	void signUpMenu();
	void guestMenu();
	
	//from logInMenu
	void customerMenu();
	void adminMenu();

	//from adminMenu
		void editMoneyMenu();
		void editItemsMenu();
		void editUsersMenu();//not finished yet

	//from editMoneyMenu
		void addMoney();
		void takeMoney();
		void setMoney();

	//from editItemsMenu
		void addToItemQuantity();
		void addItem();
		void removeItem();
		void editItem();


	//from customerMenu
		void displayCart() const;
		void addToCart();
		void removeFromCart();
		void buyItemsFromCart();
		void addMoneyToUser();

	//displayMenus
		void displayIems() const;
		void displayItemInfo() const;

public:
	Shop();
	Shop(const char* fileName);
	~Shop();

	void startMenu();
};
