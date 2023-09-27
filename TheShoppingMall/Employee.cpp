#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"

int Employee::eID = 0;

Employee::Employee(string name_a, int salary):
    name(name_a),sSalary(salary)
{
    id = ++eID;
}

void Employee::setName(string name_a)
{
    name = name_a;
}

void Employee::setSalary(int salary_e)
{
    if (salary_e < 0)
        throw GeneralException("Salary cannot be negative value");

    sSalary = salary_e;
}

bool Employee::operator>=(const Employee& other) const 
{
    return getSalary() >= other.getSalary();
}

bool Employee::operator<=(const Employee& other) const
{
    return getID() <= other.getID();
}

const Employee& Employee::operator+(int add)
{
    if (add < 0)
        throw GeneralException("Salary addition cannot be negative value");
    
    sSalary +=add;
    return *this;
}