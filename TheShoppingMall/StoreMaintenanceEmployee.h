#pragma once
using namespace std;
#include <iostream>
#include "MaintenanceEmployee.h"
#include "StoreEmployee.h"


class StoreMaintenanceEmployee : public StoreEmployee, public MaintenanceEmployee
{
private:
	int level;

public:
	StoreMaintenanceEmployee(string name, int salary, Store* store, int bonus, double storeDiscount,int level);
	
	const StoreMaintenanceEmployee& operator>=(const StoreMaintenanceEmployee& other) const;
	
	int				getLevel() const { return level; }
	void			setLevel(int newLevel);
	int				calculateSalary() const; 
	virtual void	show(ostream& out) const;
	void			maintenanceCall(const char* callReason);
};

