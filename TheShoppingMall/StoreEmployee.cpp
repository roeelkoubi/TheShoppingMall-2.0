#include "StoreEmployee.h"

StoreEmployee::StoreEmployee(string name_a, int salary, Store* store):
	Employee(name_a,salary),pStore(store)
{
}

void StoreEmployee::setStore(const Store* Store)
{
    pStore = Store;
}

void StoreEmployee::setNumOfSales(int numOfSale)
{
    if (numOfSale < 0)
        throw GeneralException("Number of sales cannot be negative");
    
    numOfSales = numOfSales;
}

int StoreEmployee::calculateSalary() const
{
    int new_salary = sSalary + (numOfSales * 50);
    return new_salary;
}

void StoreEmployee::show(ostream& out) const
{
    out << "[" << name << ", eID " << id << " earns " << sSalary << ", and had " << numOfSales << " num of sales]" << endl;
}
