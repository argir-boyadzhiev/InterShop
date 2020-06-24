#include "UserList.hpp"
#include "HelpFunctions.hpp"

UserList::UserList()
{
	users = new User[1];
	User newUser("default_admin", "admin", 12000, true);
	users[0] = newUser;
	userCount = 1;
	adminKey = new char[10];
	strCpy(adminKey, "admin_key");
}

UserList::~UserList()
{
	delete[] users;
	delete[] adminKey;
}

void UserList::addUser(const User& newUser)
{
	userCount++;
	User* newUsers = new User[userCount];
	for (int i = 0; i < userCount-1; i++) {
		newUsers[i] = users[i];
	}
	newUsers[userCount - 1] = newUser;
	delete[] users;
	users = newUsers;
}

void UserList::removeUser(int index)
{
	userCount--;
	User* newUsers = new User[userCount];
	for (int i = 0; i < index; i++) {
		newUsers[i] = users[i];
	}
	for (int i = index; i < userCount; i++) {
		newUsers[i] = users[i + 1];
	}
	delete[] users;
	users = newUsers;
}

User& UserList::getUser(int index) const
{
	return users[index];
}

int UserList::getIndexByName(const char* username) const
{
	for (int i = 0; i < userCount; i++) {
		if (strCmp(users[i].getUsername(), username) == 0) {
			return i;
		}
	}
	return -1;
}

bool UserList::tryKey(const char* newKey) const
{
	if (strCmp(newKey, adminKey) == 0) {
		return true;
	}
	else {
		return false;
	}
}
