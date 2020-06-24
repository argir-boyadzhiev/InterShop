#pragma once

int safeIntInput(int min, int max);
int safeIntInput(int min);
double safeDoubleInput(int min, int max);
double safeDoubleInput(int min);
char* safeWordInput(int maxLenght);
char* safeStringInput(int maxLenght);


int strLen(const char* arr);
int strLen(const char* arr, int maxLenght);
void strCpy(char* lhs, const char* rhs);
short strCmp(const char* arr1, const char* arr2);