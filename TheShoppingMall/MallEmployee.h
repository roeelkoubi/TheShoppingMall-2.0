#pragma once
#include <iostream>
using namespace std;
#include "Employee.h"
#include "MallExceptions.h"
#include <string.h>

class MallEmployee : public Employee
{
private:
	double	discountFee;
	int		bonus; 

public:
	MallEmployee(string name_a, int salary, double discount,int bonus_a);

	double	getDiscountFee() const { return discountFee;}
	void	setBonus(int bonus_a);
	void	setDiscountFee(double fee);
	int		calculateSalary() const override;
	void	show(ostream& out) const override;
};

