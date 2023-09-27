#pragma once
#include <iostream>
#include "Address.h"
#include "Product.h"
#include "MallExceptions.h"
#include <string.h>
#include "LinkedList.h"
using namespace std;

class Product;

class Client
{
private:
	string					name;
	string					id;
	int						bBudget;
	int						numOfProducts = 0;
	Address					pAddress;
	LinkedList<Product*>	boughtProducts;
	

public:
	static const int SIZE;
	Client(string name, string id_a, int budget, Address& address);

	string						getName() const { return name; }
	string						getID() const { return id; }
	int							getBudget() const { return bBudget; }
	const LinkedList<Product*>	getProductList() const { return boughtProducts; }
	const Address				getAddress() const { return pAddress; }
	void						setName(string name_a);
	void						setId(string id_a);
	void						setBudget(int budget_c);
	void						setAddress(const Address& address_n);
	bool						buyProduct(Product* prod);
	void						show(ostream& out) const;
};

