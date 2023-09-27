#pragma once
#include <iostream>
using namespace std;
#include "Employee.h"
#include "MallExceptions.h"

class MaintenanceEmployee: virtual public Employee
{
protected:
	int		bonusPerCall;
	int		numOfCalls = 0;

public:
	static const int SALARY_PER_HOUR;
	MaintenanceEmployee(string name_a, int salary, int bonus);

	int		getBonusPerCall() const { return bonusPerCall;}
	int		getNumOfCalls() const { return numOfCalls; }
	void	setBonusPerCall(int bonus);
	void	maintanceCall() { numOfCalls++; }
	int		calculateSalary() const override;
	void	show(ostream& out) const override;
};






