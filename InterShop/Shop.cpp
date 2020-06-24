#include "Shop.hpp"
#include "HelpFunctions.hpp"
#include "Cart.hpp"
#include <iostream>
#include <iomanip>

void Shop::addMoney()
{
	system("CLS");
	std::cout << "Input amount of money to be added: ";
	double input = safeDoubleInput(0);
	money += input;
}

void Shop::takeMoney()
{
	while (true) {
		system("CLS");
		std::cout << "Input amount of money to be taken: ";
		double input = safeDoubleInput(0);
		if (input > money) {
			system("CLS");
			std::cout << "Not enough money!\n1.Try again.\n0.Back.\n";
			int option = safeIntInput(0, 1);
			if (option == 0) {
				return;
			}
		}
		else {
			money -= input;
			return;
		}
	}
}

void Shop::setMoney()
{
	system("CLS");
	std::cout << "Input the new amount of money: ";
	double input = safeDoubleInput(0);
	money = input;
}

void Shop::displayIems() const
{
	int* order = new int[itemList.getItemArrCount()];
	int orderType = 0;
	int option = 0;
	short ascending = 1;
	

	while (true) {
		if (orderType == 0) {//order by id
			if (ascending == 1) {
				for (int i = 0; i < itemList.getItemArrCount(); i++) {
					order[i] = i;
				}
			}
			else {
				for (int i = 0; i < itemList.getItemArrCount(); i++) {
					order[i] = itemList.getItemArrCount() - i - 1;
				}
			}
			
		}
		if (orderType == 1) {//order by name
			for (int i = 0; i < itemList.getItemArrCount() - 1; i++) {
				for (int j = i + 1; j < itemList.getItemArrCount(); j++) {
					if (strCmp(itemList.getItem(order[i]).getName(), itemList.getItem(order[j]).getName()) == ascending) {
						int buffer = order[i];
						order[i] = order[j];
						order[j] = buffer;
					}
				}
			}
		}
		if (orderType == 2) {//order by price
			for (int i = 0; i < itemList.getItemArrCount() - 1; i++) {
				for (int j = i + 1; j < itemList.getItemArrCount(); j++) {
					if ((itemList.getItem(order[i]).getPrice() - itemList.getItem(order[j]).getPrice()) * ascending * (-1) < 0) {
						int buffer = order[i];
						order[i] = order[j];
						order[j] = buffer;
					}
				}
			}
		}
		system("CLS");
		std::cout << "|ID   |Name                  |Price      |Quantity   |\n";
		for (int i = 0; i < itemList.getItemArrCount(); i++) {
			std::cout << std::left;
			std::cout << "|" << std::setw(5) << itemList.getItem(order[i]).getId();
			std::cout << "|" << std::setw(22) << itemList.getItem(order[i]).getName();
			std::cout << "|" << std::setw(11) << itemList.getItem(order[i]).getPrice();
			std::cout << "|" << std::setw(11) << itemList.getItem(order[i]).getQuantity() << "|\n";
		}
		std::cout << "1.Search by name.\n2.Sort by id.\n3.Sort by name.\n4.Sort by price.\n5.Inverse order.\n0.Back.\n";
		option = safeIntInput(0, 5);
		
		if (option == 0) {
			delete[] order;
			return;
		}
		if (option == 1) {
			std::cout << "Not ready yet.\n";
			system("pause");
		}
		if (option == 2) {
			orderType = 0;
		}
		if (option == 3) {
			orderType = 1;
		}
		if (option == 4) {
			orderType = 2;
		}
		if (option == 5) {
			ascending *= -1;
		}
		//pages and search by property will be added
	}
	
}

void Shop::displayItemInfo() const
{
	
	while (true) {
		system("CLS");
		std::cout << "ID of the item: ";
		int option = safeIntInput(0);
		int index = itemList.indexOfItemBy(option);
		if (index == -1) {
			system("CLS");
			std::cout << "There no item with such ID.\n1.Try again.\n0.Back.\n";
			option = safeIntInput(0, 1);
			if (option == 0) {
				return;
			}
		}
		else {
			system("CLS");
			std::cout << "Description: ";
			std::cout << itemList.getItem(index).getDescription() << '\n';

			for (int i = 0; i < itemList.getItem(index).getProperties().getLenght(); i++) {
				std::cout << itemList.getItem(index).getProperties().getPropertyByIndex(i).getName() << ": ";
				std::cout << itemList.getItem(index).getProperties().getPropertyByIndex(i).getValue() << '\n';
			}

			system("pause");
			return;
		}
	}
}

void Shop::addToItemQuantity()
{
	
	while (true) {
		system("CLS");
		std::cout << "ID of the item: ";
		int option = safeIntInput(0);
		int index = itemList.indexOfItemBy(option);
		if (index == -1) {
			system("CLS");
			std::cout << "There no item with such ID.\n1.Try again.\n0.Back.\n";
			option = safeIntInput(0, 1);
			if (option == 0) {
				return;
			}
		}
		else {
			system("CLS");
			std::cout << "Input amount to be added: ";
			double input = safeDoubleInput(0);
			itemList.getItem(index).addToStock(input);
			return;
		}
	}
}

void Shop::addItem()
{
	PropertyList propertyList;
	char* propertyNameBuffer;
	char* propertyValueBuffer;
	system("CLS");
	std::cout << "Name: ";
	char* newName = safeWordInput(31);
	std::cout << "Description: ";
	char* newDescription = safeStringInput(501);
	std::cout << "Price: ";
	double newPrice = safeDoubleInput(0);
	std::cout << "Is the item countable 0.No 1.Yes: ";
	bool countable = (safeIntInput(0,1) == 1);
	std::cout << "Quantity: ";
	double newQuantity;
	if (countable) {
		newQuantity = safeIntInput(0);
	}
	else {
		newQuantity = safeDoubleInput(0);
	}

	while (true) {
		std::cout << "Do you want to add item property? 0.No 1.Yes: ";
		int option = safeIntInput(0, 1);
		if (option == 0) {
			break;
		}
		else {
			std::cout << "Name of property: ";
			propertyNameBuffer = safeStringInput(100);

			std::cout << "Value of property: ";
			propertyValueBuffer = safeStringInput(100);

			Property newProperty(propertyNameBuffer, propertyValueBuffer);
			delete[] propertyNameBuffer;
			delete[] propertyValueBuffer;

			propertyList.add(newProperty);
		}
	}

	Item newItem(-1, newName, newDescription, newPrice, newQuantity, countable, propertyList);
	itemList.add(newItem);
	delete[] newName;
	delete[] newDescription;
	return;
}

void Shop::removeItem()
{
	while (true) {
		system("CLS");
		std::cout << "ID of the item: ";
		int option = safeIntInput(0);
		int index = itemList.indexOfItemBy(option);
		if (index == -1) {
			system("CLS");
			std::cout << "There no item with such ID.\n1.Try again.\n0.Back.\n";
			option = safeIntInput(0, 1);
			if (option == 0) {
				return;
			}
		}
		else {
			itemList.remove(index);
			return;
		}
	}
}

void Shop::editItem()
{
	system("CLS");
	std::cout << "This option is not finished yet!\n";
	system("pause");
}

void Shop::displayCart() const
{
	Cart cart = userList.getUser(currentUser).getCart();
	system("CLS");
	std::cout << "ID | Name | Price | Quantity\n";
	for (int i = 0; i < cart.getCartSize(); i++) {
		int id = cart.getId(i);

		std::cout << id << " | ";
		std::cout << itemList.getItemById(id).getName() << " | ";
		std::cout << itemList.getItemById(id).getPrice() << " | ";
		std::cout << cart.getQuantity(i) << '\n';
	}
	system("pause");
}

void Shop::addToCart()
{
	while (true) {
		system("CLS");
		std::cout << "Insert ID of an item: \n";
		int input = safeIntInput(0);
		if (!itemList.lookForId(input)) {
			system("CLS");
			std::cout << "Tre is no such ID.\n1.Try again.\n0.Back.\n";
			int option = safeIntInput(0, 1);
			if (option == 0) {
				return;
			}
			if (option == 1) {
				continue;
			}
		}
		else {
			system("CLS");
			std::cout << "Insert quantity: \n";
			double quantity;

			if (itemList.getItemById(input).getCountable()) {
				quantity = safeIntInput(0);
			}
			else {
				quantity = safeDoubleInput(0);
			}
			
			userList.getUser(currentUser).addToCart(input, quantity);
			system("CLS");
			std::cout << "Item has been added.\n1.Add another.\n0.Back.\n";
			int option = safeIntInput(0, 1);
			if (option == 0) {
				return;
			}
			if (option == 1) {
				continue;
			}
		}
	}
}


void Shop::removeFromCart()
{
	while (true) {
		system("CLS");
		std::cout << "Insert ID of an item: \n";
		int input = safeIntInput(0);
		if (!userList.getUser(currentUser).removeFromCart(input)) {
			system("CLS");
			std::cout << "Tre is no such ID.\n1.Try again.\n0.Back.\n";
			int option = safeIntInput(0, 1);
			if (option == 0) {
				return;
			}
			if (option == 1) {
				continue;
			}
		}
		else {
			system("CLS");
			std::cout << "Item has been Removed.\n1.Remove another.\n0.Back.\n";
			int option = safeIntInput(0, 1);
			if (option == 0) {
				return;
			}
			if (option == 1) {
				continue;
			}
		}
	}
}

void Shop::buyItemsFromCart()
{
	double sumOfCart = 0;
	Cart cart = userList.getUser(currentUser).getCart();
	for (int i = 0; i < cart.getCartSize(); i++) {
		sumOfCart += cart.getQuantity(i) * itemList.getItemById(cart.getId(i)).getPrice();
	}

	if (sumOfCart > userList.getUser(currentUser).getMoney()) {
		system("CLS");
		std::cout << "You dont have enough money to make the purchase.\n";
		system("pause");
	}
	else {

		if (!itemList.takeItems(cart)) {
			system("CLS");
			std::cout << "There aren't enough items in stock.\n";
			system("pause");
			return;
		}

		system("CLS");
		std::cout << "Your cart value is "<<sumOfCart<<"lv.\nDo you wish to proceed with your purchase.\n1.Yes.\n0.No.\n";
		int option = safeIntInput(0, 1);
		if (option == 0) {
			return;
		}
		if (option == 1) {
			userList.getUser(currentUser).changeMoney(-sumOfCart);
			money += sumOfCart;
			userList.getUser(currentUser).emptyCart();
			//send items to customer 
			system("CLS");
			std::cout << "Your purchase has been completed.\n";
			system("pause");
			return;
		}
	}
}

void Shop::addMoneyToUser()
{
	system("CLS");
	std::cout << "Amount of money to be added: ";
	double input = safeDoubleInput(0);
	userList.getUser(currentUser).changeMoney(input);
}

Shop::Shop()
{
	currentUser = 0;
	fileName = new char[1];
	fileName[0] = 0;
	money = 0;
}

Shop::Shop(const char* fileName)
{
	money = 0;
	currentUser = 0;
	this->fileName = new char[strLen(fileName) + 1];
	strCpy(this->fileName, fileName);
	//create or open file with name <filename>
}

Shop::~Shop()
{
	//write to database file
	delete[] fileName;
}

void Shop::startMenu()
{
	while (true) {
		system("CLS");
		std::cout << "1. Log In.\n2.Sign Up\n3.Open as guest.\n0.Exit.\n";
		int option = safeIntInput(0, 3);
		switch (option) {
		case 0: return;
		case 1: logInMenu(); break;
		case 2: signUpMenu(); break;
		case 3: guestMenu(); break;
		}
	}
}

void Shop::logInMenu()
{
	while (true) {
		system("CLS");
		std::cout << "Input username: ";
		char* input = safeWordInput(31);
		int index = userList.getIndexByName(input);
		delete[] input;
		if (index == -1) {
			std::cout << "There is no such username in the database!\n1.Try again.\n0.Back.\n";
			int option = safeIntInput(0, 1);
			if (option == 0) {
				return;
			}
			if (option == 1) {
				continue;
			}
		}
		else {
			std::cout << "Input password: ";
			input = safeWordInput(31);
			if (userList.getUser(index).tryPass(input)) {
				delete[] input;
				currentUser = index;
				if (userList.getUser(currentUser).getAdmin()) {
					adminMenu();
					return;
				}
				else {
					customerMenu();
					return;
				}
			}
			else {
				delete[] input;
				std::cout << "Incorrect password!\n1.Try again.\n0.Back.\n";
				int option = safeIntInput(0, 1);
				if (option == 0) {
					return;
				}
				if (option == 1) {
					continue;
				}
			}
		}
	}
}

void Shop::signUpMenu()
{
	while (true) {
		system("CLS");
		std::cout << "Input username: ";
		char* username = safeWordInput(31);

		if (userList.getIndexByName(username) != -1) {
			delete[] username;
			system("CLS");
			std::cout << "This username is already taken.\n1.Try new one.\n0.Back.\n";
			int option = safeIntInput(0, 1);
			if (option == 1) {
				continue;
			}
			if (option == 0) {
				return;
			}
		}

		std::cout << "Input password: ";
		char* password = safeWordInput(31);
		system("CLS");
		std::cout << "Do you want to activate admin rights?\n1.No.\n2.Yes.\n0.Back.\n";
		int option = safeIntInput(0, 2);
		bool adminRights = false;
		if (option == 0) {
			delete[] username;
			delete[] password;
			return;
		}
		if (option == 2) {
			
			while (true) {
				system("CLS");
				std::cout << "Input admin key: ";
				char* key = safeWordInput(31);
				if (userList.tryKey(key)) {
					adminRights = true;
					delete[] key;
					break;
				}
				else {
					delete[] key;
					system("CLS");
					std::cout << "Incorrect admin key!\n1.Try again.\n2.Continue as customer.\n0.Back.\n";
					option = safeIntInput(0, 2);
					if (option == 2) {
						break;
					}
					if (option == 0) {
						return;
					}
				}
			}
		}

		User newUser(username, password, 0, adminRights);
		userList.addUser(newUser);
		delete[] username;
		delete[] password;
		return;
	}
}

void Shop::guestMenu()
{
	while (true) {
		system("CLS");
		std::cout << "1.Display items.\n2.Display item info.\n0.Back.\n";
		int option = safeIntInput(0, 2);
		switch (option) {
		case 0: return;
		case 1: displayIems(); break;
		case 2: displayItemInfo(); break;
		}
	}
}

void Shop::customerMenu()
{
	while (true) {
		system("CLS");
		std::cout << "Your balance: "<<userList.getUser(currentUser).getMoney()<<"lv.\n1.Display shop items.\n2.Display cart.\n3.Add to cart.\n4.Remove from cart.\n5.Buy items from cart.\n6.Add money.\n7.Display item info.\n0.Back.\n";
		int option = safeIntInput(0, 7);
		switch (option) {
		case 0: return;
		case 1: displayIems(); break;
		case 2: displayCart(); break;
		case 3: addToCart(); break;
		case 4: removeFromCart(); break;
		case 5: buyItemsFromCart(); break;
		case 6: addMoneyToUser(); break;
		case 7: displayItemInfo(); break;
		}
	}
}

void Shop::adminMenu()
{
	while (true) {
		system("CLS");
		std::cout << "1.Edit items.\n2.Edit users.\n3.Edit money.\n0.Back.\n";
		int option = safeIntInput(0, 3);
		switch (option) {
		case 0: return;
		case 1: editItemsMenu(); break;
		case 2: editUsersMenu(); break;
		case 3: editMoneyMenu(); break;
		}
	}
}

void Shop::editMoneyMenu()
{
	while (true) {
		system("CLS");
		std::cout << "Shop's current money: " << money << " lv.\n";
		std::cout << "1.Take money.\n2.Add money.\n3.Set money.\n0.Back.\n";
		int option = safeIntInput(0, 3);
		switch (option) {
		case 0: return;
		case 1: takeMoney(); break;
		case 2: addMoney(); break;
		case 3: setMoney(); break;
		}
	}
}

void Shop::editItemsMenu()
{
	while (true) {
		system("CLS");
		std::cout << "1.Display items.\n2.Display item info.\n3.Add to item quantity.\n4.Add item.\n5.Remove item.\n6.Edit item.\n0.Back.\n";
		int option = safeIntInput(0, 6);
		switch (option) {
		case 0: return;
		case 1: displayIems(); break;
		case 2: displayItemInfo(); break;
		case 3: addToItemQuantity(); break;
		case 4: addItem(); break;
		case 5: removeItem(); break;
		case 6: editItem(); break;
		}
	}
}

void Shop::editUsersMenu()
{
	std::cout << "This option is not finished yet!\n";
	system("pause");
}

