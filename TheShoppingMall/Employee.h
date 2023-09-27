#pragma once
#include <iostream>
#include "MallExceptions.h"
#include <string.h>
#include "Sorter.h"
using namespace std;

class Employee
{
protected:
	int			sSalary;
	string		name;
	static int	eID;
	int			id;

	
public:
	Employee(string name_a, int salary);

	string				getName() const { return name;}
	int					getID() const { return eID; }
	int					getSalary() const { return sSalary; }
	void				setName(string name_a);
	void				setSalary(int salary_e);
	bool				operator>=(const Employee& other) const;
	bool				operator<=(const Employee& other) const;
	const Employee&		operator+(int add);
	virtual int			calculateSalary() const = 0;
	virtual void		show(ostream& out) const = 0;
};