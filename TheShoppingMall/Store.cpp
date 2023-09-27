#define _CRT_SECURE_NO_WARNINGS
#include "Store.h"

Store::Store(string name_a):
    name(name_a), sortStrategy(new IdSort)
{
    clientList.reserve(20);
	employeeList.reserve(20);
	productList.reserve(40);
}

Store::~Store()
{
    for (int i = 0; i < clientList.size(); i++)
        delete clientList[i];

    for (int i = 0; i < productList.size(); i++)
        delete productList[i];

    for (int i = 0; i < employeeList.size(); i++)
        delete employeeList[i];
}

void Store::setName(string name_a)
{
    name = name_a;
}

void Store::showAllEmployeesInStore() const
{
    if (!employeeList.size())
        cout << "There are no employees in this store" << endl;
    else
    {
        for (int i = 0; i < employeeList.size(); i++)
        {
            cout << i + 1 << ". ";
            employeeList[i]->show(cout);
        }
    }
}

void Store::showAllProducts() const
{
    if (!employeeList.size())
        cout << "There are no products in this store" << endl;
    else
    {
        for (int i = 0; i < productList.size(); i++)
        {
            cout << i + 1 << ". ";
            productList[i]->show(cout);
        }
    }
}

void Store::showAllClients(bool nameOnly) const
{
    if (!clientList.size())
        cout << "There are no clients in this store" << endl;
    else
    {
        for (int i = 0; i < clientList.size(); i++)
        {
            cout << i + 1 << ". ";
            if (nameOnly)
                cout << clientList[i]->getName() << endl;
            else
                clientList[i]->show(cout);
        }
    }
}

bool Store::addEmployee(StoreEmployee* emp)
{
    employeeList.push_back(emp);
    return true;
}

bool Store::addClient(Client* client)
{
    clientList.push_back(client);
    return true;
}

bool Store::addProduct(Product* prod)
{
    productList.push_back(prod);
    return true;
}

bool Store::checkPID(int id)
{
    for (int i = 0; i < productList.size(); i++)
        if (productList[i]->getPID() == id)
        {
            cout << "Product ID already exists in this store." << endl;
            return false;
        }

    return true;
}

bool Store::clientBuyProduct(int client, int product)
{
    if (!clientList[client]->buyProduct(productList[product]))
        return false;

    return true;
}

void Store::setSortStrategy(Sorter* strategy)
{

    delete sortStrategy;
    sortStrategy = strategy;

}
