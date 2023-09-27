#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"

const int Client::SIZE = 50;

Client::Client(string name_a, string id_a, int budget, Address& address):
    name(name_a),id(id_a),pAddress(address),bBudget(budget)
{}

void Client::setName(string name_a)
{
    name = name_a;
}

void Client::setId(string id_a)
{
    id = id_a;
}

void Client::setBudget(int budget_c)
{
    if (budget_c < 0)
        throw GeneralException("Budget have to be positive value");

    bBudget = budget_c;
}


void Client::setAddress(const Address& address_n)
{
    pAddress = address_n;
}

bool Client::buyProduct(Product* prod)
{
    if ((bBudget - prod->getPrice()) < 0)
        return false;

    bBudget -= prod->getPrice();
    boughtProducts.insert(prod);
    numOfProducts++;
    return true;
}

void Client::show(ostream& out) const
{
    out << "Client Name: " << name << endl;
    out << "ID: " << id << endl;
    out << "Budget: " << bBudget << endl;
    out << "Number of Bought Products: " << numOfProducts << endl;
    if (numOfProducts > 0)
    {
        out << "Products Bought: " << endl;
        for (int i = 0; i < numOfProducts; i++)
            out << "- " << boughtProducts.getNodeByIndex(i)->getName() << endl;
    }
    out << "Address: ";
    out << pAddress.getCity();
    out << ", " << pAddress.getStreet();
    out << ", House Number: " << pAddress.getHouseNum() << endl;
}