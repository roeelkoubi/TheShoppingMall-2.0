#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Store.h"
#include "Restaurant.h"
#include "Entertainment.h"
#include "SpecialtyStore.h"
#include "GeneralFunctions.h"

typedef enum {
	eRestaurant = 1,
	eEntertainment,
	eSpecialty,
} STORE_TYPE;

class StoreFactory
{
public:
	static Store* createStore(int type);
};