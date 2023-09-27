#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;

int		getIntFromUser(const char* msg, size_t min, size_t max);
double	getDoubleFromUser(const char* msg, double min, double max);
void	cleanBuffer();
void	showMenu();


