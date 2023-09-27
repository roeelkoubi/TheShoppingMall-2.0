#include "StoreMaintenanceEmployee.h"

StoreMaintenanceEmployee::StoreMaintenanceEmployee(string name_a, int salary, Store* store, int bonus, double storeDiscount, int lvl):
   Employee(name_a,salary), StoreEmployee(name_a, salary, store), MaintenanceEmployee(name_a, salary, bonus),level(lvl)
{
}

int  StoreMaintenanceEmployee::calculateSalary() const
{
    int newSalary = sSalary + (numOfCalls * bonusPerCall) + (level * 100);
    return newSalary;
}


void StoreMaintenanceEmployee::maintenanceCall(const char* callReason)
{
    cout << "[" << name << " was fix the " << callReason << ", in the store  " << getStore() << "]" << endl;
}


void StoreMaintenanceEmployee::setLevel(int newLevel) {
    if (newLevel >= 1 && newLevel <= 3)
        level = newLevel;
    else
        level = 1;
}

const StoreMaintenanceEmployee& StoreMaintenanceEmployee::operator>=(const StoreMaintenanceEmployee& other) const
{
    if (level >= other.getLevel())
        return *this;
    else
        return other;
}


void StoreMaintenanceEmployee::show(ostream& out) const
{
    out << "[" << name << ", eID " << id << " with level " << level << ", and salary of " << sSalary << ", had " << numOfCalls << " maintenance calls until now]" << endl;
}


