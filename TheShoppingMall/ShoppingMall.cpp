#define _CRT_SECURE_NO_WARNINGS
#include "ShoppingMall.h"

ShoppingMall::ShoppingMall(string name_a, Address& add):
	name(name_a), aAddress(add)
{
    storeList.reserve(15);
    employeeList.reserve(15);
}

ShoppingMall::~ShoppingMall()
{
    for (int i = 0; i < storeList.size(); i++)
        delete storeList[i];

    for (int i = 0; i < employeeList.size(); i++)
        delete employeeList[i];
}

void ShoppingMall::maintenanceCallAlert(Store* sTemp, string type)
{
    bool loop = true;
    time_t currentTime = time(nullptr);
    string timeString = ctime(&currentTime);
    while (loop)
    {
        int randomNumber = rand() % (employeeList.size());
        const type_info& typeInfo = typeid(employeeList[randomNumber]);
        if (typeid(*employeeList[randomNumber]) == typeid(MaintenanceEmployee))
        {
            MaintenanceEmployee* maintenanceEmp = dynamic_cast<MaintenanceEmployee*>(employeeList[randomNumber]);
            maintenanceEmp->maintanceCall();

            cout << "We got new maintenance Call Alert at " << sTemp->getName() << endl;
            cout << employeeList[randomNumber]->getName() << " Take care of this call" << endl;
            cout << "Current time: " << timeString;
            cout << "reason of the call: " << type << endl;
            loop = false;
        }
    }
}

void ShoppingMall::setName(string name_a)
{
    name = name_a;
}

bool ShoppingMall::addStore(Store* store)
{
    storeList.push_back(store);
    return true;
}

bool ShoppingMall::addEmployee(Employee* emp)
{
    employeeList.push_back(emp);
    return true;
}

void ShoppingMall::showAllStores() const
{
    for (int i = 0; i < storeList.size(); i++)
    {
        cout << i + 1 << ". ";
        storeList[i]->show(cout);
    }
}

void ShoppingMall::showAllEmployees() const
{
    for (int i = 0; i < employeeList.size(); i++)
    {
        cout << i + 1 << ". ";
        employeeList[i]->show(cout);
    }
}

void ShoppingMall::show(ostream& out) const
{
    out << "Shopping Mall Name: " << name << endl;
    out << "Address " << aAddress <<endl;
    out << endl;
    out << "Employees that working in this shooping mall: " << endl;
    showAllEmployees();
    out << endl;
    size_t counter = 0;
    for (int i = 0; i < storeList.size(); i++)
    {
        counter += storeList[i]->getEmployeeList().size();
        out << "Store " << storeList[i]->getName() << " Has the following employees: " << endl;
        storeList[i]->showAllEmployeesInStore();
        out << endl;
    }
    out << "In this shopping mall there are " << counter << " employees in " << storeList.size() << " diffrent stores" << endl;
}