#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include "Address.h"
#include "Store.h"
#include "MaintenanceEmployee.h"
#include "Employee.h"
#include "MallExceptions.h"
using namespace std;

class Store;

class ShoppingMall
{

private:
	string 				name;
	Address				aAddress;
	vector<Store*>		storeList;
	vector<Employee*>	employeeList; 

public:
	ShoppingMall(string name_a, Address& add);
	~ShoppingMall();

	string					getName() const { return name; } 
	const Address			getAddress() const { return aAddress; }
	const vector<Store*>	getStoreList() const { return storeList; }
	void					showAllStores() const;
	void					showAllEmployees() const;
	Store*					getStoreByIndex(int index) const { return storeList[index]; }
	void					maintenanceCallAlert(Store* sTemp, string type);
	void					setName(string name_a);
	bool					addStore(Store* store);
	bool					addEmployee(Employee* emp);
	void					show(ostream& out) const;
};