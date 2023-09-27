#include "EmployeeFactory.h"

Employee* EmployeeFactory::createEmployee(int type, Store* store)
{
    Employee* pTemp = nullptr;
    cleanBuffer();
    switch (type)
    {
    case eStoreEmployee:
    {
        cout << "Please enter Employee name:\n";
        string name;
        getline(cin, name);

        int salary = getIntFromUser("employee salary", 1, 200);

        pTemp = new StoreEmployee(name, salary, store);
        break;
    }
    case eMallEmployee:
    {
        cout << "Please enter Employee name:\n";
        string name;
        getline(cin, name);

        int salary = getIntFromUser("employee salary", 1, 200);
        double discountFee = getDoubleFromUser("employee discount fee", 0.0, 1.0);
        int bonus = getIntFromUser("employee bonus", 1, 200);

        pTemp = new MallEmployee(name, salary, discountFee, bonus);
        break;
    }
    case eMaintenanceEmployee:
    {
        cout << "Please enter Employee name:\n";
        string name;
        getline(cin, name);

        int salary = getIntFromUser("employee salary", 1, 200);
        int bonus = getIntFromUser("employee bonus", 1, 200);

        pTemp = new MaintenanceEmployee(name, salary, bonus);
        break;
    }
    case eStoreMaintenanceEmployee:
    {
        cout << "Please enter Employee name:\n";
        string name;
        getline(cin, name);

        int salary = getIntFromUser("employee salary", 1, 200);
        int bonus = getIntFromUser("employee bonus", 1, 200);
        double storeDiscount = getDoubleFromUser("employee discount fee", 0.0, 1.0);
        int level = getIntFromUser("employee level", 1, 3);

        pTemp = new StoreMaintenanceEmployee(name, salary, store, bonus, storeDiscount, level);
        break;
    }
    default:
        cout << "Employee type does not exists." << endl;
        break;
    }
    return pTemp;
}
