#include "HelpFunctions.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int safeIntInput(int min, int max)
{
	double input;
	while (true) {
		cin >> input;
		cin.get();
		if (cin.fail()) {
			cout << "Input must be a whole number between " << min << " and " << max << " !\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (input < min || input > max || (round(input) != input)) {
			cout << "Input must be a whole number between " << min << " and " << max << " !\n";
		}
		else {
			return (int)input;
		}
		
	}
}

int safeIntInput(int min)
{
	double input;
	while (true) {
		cin >> input;
		cin.get();
		if (cin.fail()) {
			cout << "Input must be a whole number equal or bigger than " << min << " !\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (input < min || (round(input) != input)) {
			cout << "Input must be a whole number equal or bigger than " << min << " !\n";
		}
		else {
			return input;
		}

	}
}

double safeDoubleInput(int min, int max)
{
	double input;
	while (true) {
		cin >> input;
		cin.get();
		if (cin.fail()) {
			cout << "Input must be a number between " << min << " and " << max << " !\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (input < min || input > max) {
			cout << "Input must be a number between " << min << " and " << max << " !\n";
		}
		else {
			return input;
		}

	}
}

double safeDoubleInput(int min)
{
	double input;
	while (true) {
		cin >> input;
		cin.get();
		if (cin.fail()) {
			cout << "Input must be a number equal or bigger than " << min << " !\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (input < min) {
			cout << "Input must be a number equal or bigger than " << min << " !\n";
		}
		else {
			return input;
		}

	}
}

char* safeWordInput(int maxLenght)
{
	char* initialArr = new char[maxLenght + 50];

	while (true) {
		bool skip = false;
		cin.getline(initialArr, maxLenght + 50);
		if (strLen(initialArr, maxLenght) == -1 || strLen(initialArr, maxLenght) == 0) {
			cout << "Input must have less characters than " << maxLenght << " !\n";
		}
		else {
			for (int i = 0; initialArr[i] != 0; i++) {
				if ((initialArr[i] < 'a' || initialArr[i]>'z') && (initialArr[i] < 'A' || initialArr[i] > 'Z') && (initialArr[i] < '0' || initialArr[i] > '9') && initialArr[i] != '_') {
					cout << "Input can contain only A-Z, a-z, 0-9 and _ !\n";
					skip = true;
					break;
				}
			}

			if (skip) {
				continue;
			}
			char* endArr = new char[strLen(initialArr) + 1];
			strCpy(endArr, initialArr);
			delete[] initialArr;

			return endArr;
		}
	}
}

char* safeStringInput(int maxLenght)
{
	char* initialArr = new char[maxLenght + 50];

	while (true) {
		bool skip = false;
		cin.getline(initialArr, maxLenght + 50);
		if (strLen(initialArr, maxLenght) == -1 || strLen(initialArr, maxLenght) == 0) {
			cout << "Input must have less characters than " << maxLenght << " !\n";
		}
		else {
			for (int i = 0; initialArr[i] != 0; i++) {
				if ((initialArr[i] < 'a' || initialArr[i]>'z') && (initialArr[i] < 'A' || initialArr[i] > 'Z') && (initialArr[i] < '0' || initialArr[i] > '9') && initialArr[i] != ' ' && initialArr[i] != '_' && initialArr[i] != '.' && initialArr[i] != ',' && initialArr[i] != '-') {
					cout << "Input can contain only A-Z, a-z, 0-9 and _ !\n";
					skip = true;
					break;
				}
			}

			if (skip) {
				continue;
			}
			char* endArr = new char[strLen(initialArr) + 1];
			strCpy(endArr, initialArr);
			delete[] initialArr;

			return endArr;
		}
	}
}

int strLen(const char* arr) {
	int i = 0;
	for (; arr[i] != 0; i++);
	return i;
}

int strLen(const char* arr, int maxLenght)
{
	int i = 0;
	for (; arr[i] != 0; i++) {
		if (i == maxLenght) {
			return -1;
		}
	}
	return i;
}

void strCpy(char* lhs, const char* rhs) {
	int i = 0;
	for (; rhs[i] != 0; i++) {
		lhs[i] = rhs[i];
	}
	lhs[i] = 0;
}

short strCmp(const char* arr1, const char* arr2) {
	for (int i = 0; true; i++) {
		if (arr1[i] < arr2[i]) {
			return -1;
		}
		else if (arr1[i] > arr2[i]) {
			return 1;
		}
		else if (arr1[i] == 0 && arr2[i] == 0) {
			return 0;
		}
	}
}