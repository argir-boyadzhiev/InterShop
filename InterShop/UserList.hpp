#pragma once
#include "User.hpp"

class UserList {
private:
	User* users;
	int userCount;
	char* adminKey;//used for signing up as an admin
public:
	UserList();
	~UserList();

	//getters
	User& getUser(int index) const;
	int getIndexByName(const char* username) const;

	//other methods
	void addUser(const User& newUser);
	void removeUser(int index);
	bool tryKey(const char* newKey) const;
	

};
