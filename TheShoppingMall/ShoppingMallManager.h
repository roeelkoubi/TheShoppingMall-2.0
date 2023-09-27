#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include "ShoppingMall.h"
#include "GeneralFunctions.h"
#include "Store.h"
#include "Product.h"
#include "StoreFactory.h"
#include "EmployeeFactory.h"
#include "MallExceptions.h"
using namespace std;

class ShoppingMallManager // Singleton 
{
private:
	ShoppingMall* theMall;
	static ShoppingMallManager* manager;
	static int					usersCount;
	ShoppingMallManager();

public:
	~ShoppingMallManager();

	static ShoppingMallManager*		getManagerInstance();
	void							releaseManagerInstance();
	ShoppingMall*					createShoppingMall();
	void							createStore();
	void							createEmployee();
	void							createProduct(Store* sto);
	void							createClient();
	void							showMallEmployees();
	void							showMallStores();
	void							showMall();
	void							selectStoreMenu();
	void							sortProductList(Store* store);
	void							hardCoded();
};