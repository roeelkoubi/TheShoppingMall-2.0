#pragma once
#include <iostream>
using namespace std;
#include "Employee.h"
#include "MallExceptions.h"

class Store;

class StoreEmployee : virtual public Employee
{
protected:
	const Store*	pStore;
	int				numOfSales = 0;

public:
	StoreEmployee(string name_a, int salary, Store* store);

	const Store*	getStore() const { return pStore; } 
	void			setStore(const Store* store);
	void			setNumOfSales(int numOfSale);
	int				calculateSalary() const override;
	virtual void	show(ostream& out) const override;
};